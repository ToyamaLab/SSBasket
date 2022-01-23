package supersql.recursivesearch;

import java.util.ArrayList;
import java.util.List;
public class RecursiveTreeGenerator <K extends Comparable<? super K>,V>{

	    //=========================================================================
	    // 共通定義
	    //=========================================================================

	    private static final int m  = 5;           // B木のオーダー
	    private static final int hm = (m + 1) / 2; // B木の最小分岐数[m/2]

	    private class Pair { // 要素の型
	        K key;
	        V value;
	        Pair(K key, V x) { this.key = key; this.value = x; }
	    }

	    private abstract class Node { // ノードの型(抽象型)
	        List<Pair> es = new ArrayList<Pair>(m);     // 要素のリスト
	        List<Node> ns = new ArrayList<Node>(m + 1); // 枝のリスト

	        // 挿入時のアクティブなノードを通常のノードへ変換する
	        abstract Node deactivate();

	        // 枝が１本の余分なノードを切り詰める
	        Node trim() { return ns.size() == 1 ? ns.get(0) : this; }
	    }
	    private Node root = null; // B木の根

	    private class NodeA extends Node { // 挿入時のアクティブなノードの型
	        NodeA(Pair e, Node l, Node r) { es.add(e); ns.add(l); ns.add(r); }
	        Node deactivate() { return new NodeN(es.get(0), ns.get(0), ns.get(1)); }
	    }

	    private class NodeN extends Node { // 通常のノードの型
	        NodeN() {}
	        NodeN(Pair e, Node l, Node r) { es.add(e); ns.add(l); ns.add(r); }
	        Node deactivate() { return this; }
	    }

	    // 挿入時のアクティブなノードを判定する
	    private boolean activeI(Node t) { return t instanceof RecursiveTreeGenerator<?,?>.NodeA; }

	    // 削除時のアクティブなノードを判定する
	    private boolean activeD(Node t) { return t != null && t.ns.size() < hm; }

	    //=========================================================================
	    // insert(挿入)
	    //=========================================================================

	    // 木 root にキー key で値 x を挿入する
	    public void insert(K key, V x) {
	        root = insert(root, new Pair(key, x)).deactivate();
	    }

	    // 木 t に要素 e を挿入する
	    private Node insert(Node t, Pair e) {
	        if (t == null) return new NodeA(e, null, null);
	        int i;
	        for (i = 0; i < t.es.size(); i++) {
	            final int cmp = e.key.compareTo(t.es.get(i).key);
	            if (cmp < 0) {
	                t.ns.set(i, insert(t.ns.get(i), e));
	                return balance(t, i);
	            }
	            else if (cmp == 0) {
	                t.es.set(i, e);
	                return t;
	            }
	        }
	        t.ns.set(i, insert(t.ns.get(i), e));
	        return balance(t, i);
	    }

	    //=========================================================================
	    // 挿入時のバランスの調整
	    //=========================================================================

	    // 挿入時のアクティブなノードと反応して木を変形する
	    // アクティブでなければ何もしない
	    private Node balance(Node t, int i) {
	        Node ni = t.ns.get(i);
	        if (!activeI(ni)) return t;
	        // 以下、ni はアクティブ。つまり２分岐
	        t.es.add(i, ni.es.get(0));
	        t.ns.set(i, ni.ns.get(1));
	        t.ns.add(i, ni.ns.get(0));
	        return t.es.size() < m ? t : split(t);
	    }

	    // 要素数が m のノードを分割してアクティブなノードに変換する
	    private Node split(Node t) {
	        int j = hm, i = j - 1;
	        Node r = new NodeN();
	        r.es.addAll(t.es.subList(j, m));
	        r.ns.addAll(t.ns.subList(j, m + 1));
	        t.es.subList(j, m).clear();
	        t.ns.subList(j, m + 1).clear();
	        return new NodeA(t.es.remove(i), t, r);
	    }

	    //=========================================================================
	    // delete(削除)
	    //=========================================================================

	    // 木 root からキー key のノードを削除する
	    public void delete(K key) {
	        if (root == null) return;
	        delete(root, key);
	        root = root.trim();
	    }

	    // 木 t からキー key のノードを削除する
	    private void delete(Node t, K key) {
	        if (t == null) return;
	        int i;
	        for (i = 0; i < t.es.size(); i++) {
	            final int cmp = key.compareTo(t.es.get(i).key);
	            if (cmp < 0) {
	                delete(t.ns.get(i), key);
	                balanceL(t, i);
	                return;
	            }
	            else if (cmp == 0) {
	                if (t.ns.get(i) == null) {
	                    // 最下層のノードでの削除
	                    t.es.remove(i);
	                    t.ns.remove(i);
	                }
	                else {
	                    // 内部ノードでの削除
	                    t.es.set(i, deleteMax(t.ns.get(i)));
	                    balanceL(t, i);
	                }
	                return;
	            }
	        }
	        delete(t.ns.get(i), key);
	        balanceR(t, i);
	    }

	    // 部分木 t の最大値キーの要素を削除する
	    // 削除した最大値キーの要素を返す
	    private Pair deleteMax(Node t) {
	        int j = t.es.size(), i = j - 1;
	        if (t.ns.get(j) != null) {
	            Pair e = deleteMax(t.ns.get(j));
	            balanceR(t, j);
	            return e;
	        }
	        else {
	            t.ns.remove(j);
	            return t.es.remove(i);
	        }
	    }

	    //=========================================================================
	    // 削除時のバランスの調整
	    //=========================================================================

	    // 削除時のアクティブなノードと反応して木を変形する
	    // アクティブでなければ何もしない
	    private void balanceL(Node t, int i) {
	        Node ni = t.ns.get(i);
	        if (!activeD(ni)) return;
	        // 以下、ni がアクティブな場合。つまり枝の数が hm より少ない
	        int j = i + 1;
	        Pair e  = t.es.get(i);
	        Node nj = t.ns.get(j);
	        if (nj.ns.size() == hm) {
	            // nj に余裕がない場合(融合)
	            ni.es.add(e);
	            ni.es.addAll(nj.es);
	            ni.ns.addAll(nj.ns);
	            t.es.remove(i);
	            t.ns.remove(j);
	        }
	        else t.es.set(i, moveRL(e, ni, nj)); // nj に余裕がある場合
	    }

	    // 削除時のアクティブなノードと反応して木を変形する
	    // 最も右の部分木がアクティブな場合の処理
	    // アクティブでなければ何もしない
	    private void balanceR(Node t, int j) {
	        Node nj = t.ns.get(j);
	        if (!activeD(nj)) return;
	        // 以下、nj がアクティブな場合。つまり枝の数が hm より少ない
	        int i = j - 1;
	        Pair e  = t.es.get(i);
	        Node ni = t.ns.get(i);
	        if (ni.ns.size() == hm) {
	            // ni に余裕がない場合(融合)
	            ni.es.add(e);
	            ni.es.addAll(nj.es);
	            ni.ns.addAll(nj.ns);
	            t.es.remove(i);
	            t.ns.remove(j);
	        }
	        else t.es.set(i, moveLR(e, ni, nj)); // ni に余裕がある場合
	    }

	    // 余裕のある右のノードから枝を１本分けてもらう
	    private Pair moveRL(Pair e, Node l, Node r) {
	        l.es.add(e);
	        l.ns.add(r.ns.remove(0));
	        return r.es.remove(0);
	    }

	    // 余裕のある左のノードから枝を１本分けてもらう
	    private Pair moveLR(Pair e, Node l, Node r) {
	        int j = l.es.size(), i = j - 1;
	        r.es.add(0, e);
	        r.ns.add(0, l.ns.remove(j));
	        return l.es.remove(i);
	    }

	    //=========================================================================
	    // 検索等
	    //=========================================================================

	    // キーの検索。ヒットすれば true、しなければ false
	    public boolean member(K key) {
	        Node t = root;
	        while (t != null) {
	            int i;
	            for (i = 0; i < t.es.size(); i++) {
	                final int cmp = key.compareTo(t.es.get(i).key);
	                if      (cmp <  0) break;
	                else if (cmp == 0) return true;
	            }
	            t = t.ns.get(i);
	        }
	        return false;
	    }

	    // キーから値を得る。キーがヒットしない場合は null を返す
	    public V lookup(K key) {
	        Node t = root;
	        while (t != null) {
	            int i;
	            for (i = 0; i < t.es.size(); i++) {
	                final int cmp = key.compareTo(t.es.get(i).key);
	                if      (cmp <  0) break;
	                else if (cmp == 0) return t.es.get(i).value;
	            }
	            t = t.ns.get(i);
	        }
	        return null;
	    }

	    // マップが空なら true、空でないなら false
	    public boolean isEmpty() { return root == null; }

	    // マップを空にする
	    public void clear() { root = null; }

	    // キーのリスト
	    public ArrayList<K> keys() {
	        ArrayList<K> al = new ArrayList<K>();
	        keys(root, al);
	        return al;
	    }

	    // 値のリスト
	    public ArrayList<V> values() {
	        ArrayList<V> al = new ArrayList<V>();
	        values(root, al);
	        return al;
	    }

	    // マップのサイズ
	    public int size() { return keys().size(); }

	    // キーの最小値
	    public K min() {
	        Node t = root;
	        if (t == null) return null;
	        while (t.ns.get(0) != null) t = t.ns.get(0);
	        return t.es.get(0).key;
	    }

	    // キーの最大値
	    public K max() {
	        Node t = root;
	        if (t == null) return null;
	        while (t.ns.get(t.es.size()) != null) t = t.ns.get(t.es.size());
	        return t.es.get(t.es.size() - 1).key;
	    }

	    private void keys(Node t, ArrayList<K> al) {
	        if (t != null) {
	            int i;
	            for (i = 0; i < t.es.size(); i++) {
	                keys(t.ns.get(i), al);
	                al.add(t.es.get(i).key);
	            }
	            keys(t.ns.get(i), al);
	        }
	    }

	    private void values(Node t, ArrayList<V> al) {
	        if (t != null) {
	            int i;
	            for (i = 0; i < t.es.size(); i++) {
	                values(t.ns.get(i), al);
	                al.add(t.es.get(i).value);
	            }
	            values(t.ns.get(i), al);
	        }
	    }

	    //=========================================================================
	    // debug 用ルーチン
	    //=========================================================================

	    // B木をグラフ文字列に変換する
	    public String toString() {
	        return toGraph("", root).replaceAll("\\s+$", "");
	    }

	    // B木のバランスが取れているか確認する
	    public boolean balanced() { return balanced(root); }

	    // 多分探索木になっているか確認する
	    public boolean mstValid() { return mstValid(root); }

	    // B木の根と葉を除くノードが hm 以上の枝を持っているか確認する
	    public boolean dense() {
	        if (root == null) return true;
	        int n = root.ns.size();
	        if (n < 2 || m < n) return false;
	        for (int i = 0; i < n; i++)
	            if (!denseHalf(root.ns.get(i))) return false;
	        return true;
	    }

	    private static final String nl = System.getProperty("line.separator");
	    private String toGraph(String head, Node t) {
	        if (t == null) return "";
	        int i = t.ns.size();
	        String graph = toGraph(head + "    ", t.ns.get(--i));
	        graph += head + "∧" + nl;
	        do {
	            graph += head + t.es.get(--i).key + nl;
	            if (i == 0) graph += head + "∨" + nl;
	            graph += toGraph(head + "    ", t.ns.get(i));
	        } while (i > 0);
	        return graph;
	    }

	    private boolean balanced(Node t) {
	        if (t == null) return true;
	        if (!balanced(t.ns.get(0))) return false;
	        int h = height(t.ns.get(0));
	        for (int i = 1; i < t.ns.size(); i++) {
	            if (!balanced(t.ns.get(i))) return false;
	            if (h != height(t.ns.get(i))) return false;
	        }
	        return true;
	    }

	    // 木の高さを返す
	    private int height(Node t) {
	        if (t == null) return 0;
	        int mx = height(t.ns.get(0));
	        for (int i = 1; i < t.ns.size(); i++) {
	            int h = height(t.ns.get(i));
	            if (h > mx) mx = h;
	        }
	        return 1 + mx;
	    }

	    private boolean mstValid(Node t) {
	        if (t == null) return true;
	        K key = t.es.get(0).key;
	        if (!small(key, t.ns.get(0))) return false;
	        if (!mstValid(t.ns.get(0))) return false;
	        int i;
	        for (i = 1; i < t.es.size(); i++) {
	            K key1 = t.es.get(i - 1).key;
	            K key2 = t.es.get(i).key;
	            if (!(key1.compareTo(key2) < 0)) return false;
	            if (!between(key1, key2, t.ns.get(i))) return false;
	            if (!mstValid(t.ns.get(i))) return false;
	        }
	        key = t.es.get(i - 1).key;
	        if (!large(key, t.ns.get(i))) return false;
	        if (!mstValid(t.ns.get(i))) return false;
	        return true;
	    }

	    private boolean small(K key, Node t) {
	        if (t == null) return true;
	        int i;
	        for (i = 0; i < t.es.size(); i++) {
	            if (!small(key, t.ns.get(i))) return false;
	            if (!(key.compareTo(t.es.get(i).key) > 0)) return false;
	        }
	        if (!small(key, t.ns.get(i))) return false;
	        return true;
	    }

	    private boolean between(K key1, K key2, Node t) {
	        if (t == null) return true;
	        int i;
	        for (i = 0; i < t.es.size(); i++) {
	            if (!between(key1, key2, t.ns.get(i))) return false;
	            if (!(key1.compareTo(t.es.get(i).key) < 0)) return false;
	            if (!(key2.compareTo(t.es.get(i).key) > 0)) return false;
	        }
	        if (!between(key1, key2, t.ns.get(i))) return false;
	        return true;
	    }

	    private boolean large(K key, Node t) {
	        if (t == null) return true;
	        int i;
	        for (i = 0; i < t.es.size(); i++) {
	            if (!large(key, t.ns.get(i))) return false;
	            if (!(key.compareTo(t.es.get(i).key) < 0)) return false;
	        }
	        if (!large(key, t.ns.get(i))) return false;
	        return true;
	    }

	    private boolean denseHalf(Node t) {
	        if (t == null) return true;
	        int n = t.ns.size();
	        if (n < hm || m < n) return false;
	        for (int i = 0; i < n; i++)
	            if (!denseHalf(t.ns.get(i))) return false;
	        return true;
	    }

	    //=========================================================================
	    // メインルーチン
	    //=========================================================================

	    public static void main(String[] args) {
	        final int n = 30;
	        RecursiveTreeGenerator<Integer,Integer> m = new RecursiveTreeGenerator<>();
	        ArrayList<Integer> keys = new ArrayList<>();
	        for (int i = 0; i < n; i++) keys.add(i);
	        java.util.Collections.shuffle(keys);
	        for (int i = 0; i < n; i++) m.insert(keys.get(i), i);
	        System.out.println(m);
	        System.out.println();
	        System.out.println("size: " + m.size());
	        System.out.println("keys: " + m.keys());

	        final int N = 1000000;
	        java.util.Random rng = new java.util.Random();
	        m.clear();
	        java.util.TreeMap<Integer,Integer> answer = new java.util.TreeMap<>();
	        int insertErrors = 0;
	        int deleteErrors = 0;
	        for (int i = 0; i < N; i++) {
	            int key = rng.nextInt(N);
	            m.insert(key, i);
	            answer.put(key, i);
	        }
	        for (int key: answer.keySet()) {
	            int x = m.lookup(key);
	            int y = answer.get(key);
	            if (x != y) insertErrors++;
	        }
	        int half = answer.size()/2;
	        for (int key: answer.keySet()) {
	            if (half-- == 0) break;
	            m.delete(key);
	        }
	        half = answer.size()/2;
	        for (int key: answer.keySet()) {
	            if (half-- == 0) break;
	            if (m.member(key)) deleteErrors++;
	        }
	        System.out.println();
	        System.out.println("バランス:   " + (m.balanced()      ? "OK" : "NG"));
	        System.out.println("多分探索木: " + (m.mstValid()      ? "OK" : "NG"));
	        System.out.println("密度:       " + (m.dense()         ? "OK" : "NG"));
	        System.out.println("挿入:       " + (insertErrors == 0 ? "OK" : "NG"));
	        System.out.println("削除:       " + (deleteErrors == 0 ? "OK" : "NG"));
	        for (int key: m.keys()) m.delete(key);
	        System.out.println("全削除:     " + (m.isEmpty()       ? "OK" : "NG"));
	    }

}
