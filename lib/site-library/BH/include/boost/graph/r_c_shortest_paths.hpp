// r_c_shortest_paths.hpp header file

// Copyright Michael Drexl 2005, 2006.
// Distributed under the Boost Software License, Version 1.0.
<<<<<<< HEAD
// (See accompanying file LICENSE_1_0.txt or copy at 
=======
// (See accompanying file LICENSE_1_0.txt or copy at
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
// http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GRAPH_R_C_SHORTEST_PATHS_HPP
#define BOOST_GRAPH_R_C_SHORTEST_PATHS_HPP

#include <map>
#include <queue>
#include <vector>
#include <list>

<<<<<<< HEAD
=======
#include <boost/make_shared.hpp>
#include <boost/enable_shared_from_this.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/iteration_macros.hpp>
#include <boost/property_map/property_map.hpp>

namespace boost {

// r_c_shortest_paths_label struct
template<class Graph, class Resource_Container>
<<<<<<< HEAD
struct r_c_shortest_paths_label
{
  r_c_shortest_paths_label
  ( const unsigned long n, 
    const Resource_Container& rc = Resource_Container(), 
    const r_c_shortest_paths_label* const pl = 0, 
    const typename graph_traits<Graph>::edge_descriptor& ed = 
      graph_traits<Graph>::edge_descriptor(), 
    const typename graph_traits<Graph>::vertex_descriptor& vd = 
      graph_traits<Graph>::vertex_descriptor() )
  : num( n ), 
    cumulated_resource_consumption( rc ), 
    p_pred_label( pl ), 
    pred_edge( ed ), 
    resident_vertex( vd ), 
    b_is_dominated( false ), 
    b_is_processed( false ),
    b_is_valid( true )
  {}
=======
struct r_c_shortest_paths_label : public boost::enable_shared_from_this<r_c_shortest_paths_label<Graph, Resource_Container> >
{
  r_c_shortest_paths_label
  ( const unsigned long n,
    const Resource_Container& rc = Resource_Container(),
    const boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > pl = boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> >(),
    const typename graph_traits<Graph>::edge_descriptor& ed = graph_traits<Graph>::edge_descriptor(),
    const typename graph_traits<Graph>::vertex_descriptor& vd = graph_traits<Graph>::vertex_descriptor() )
  : num( n ),
    cumulated_resource_consumption( rc ),
    p_pred_label( pl ),
    pred_edge( ed ),
    resident_vertex( vd ),
    b_is_dominated( false ),
    b_is_processed( false )
  {}

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  r_c_shortest_paths_label& operator=( const r_c_shortest_paths_label& other )
  {
    if( this == &other )
      return *this;
    this->~r_c_shortest_paths_label();
    new( this ) r_c_shortest_paths_label( other );
    return *this;
  }
  const unsigned long num;
  Resource_Container cumulated_resource_consumption;
<<<<<<< HEAD
  const r_c_shortest_paths_label* const p_pred_label;
=======
  const boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > p_pred_label;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  const typename graph_traits<Graph>::edge_descriptor pred_edge;
  const typename graph_traits<Graph>::vertex_descriptor resident_vertex;
  bool b_is_dominated;
  bool b_is_processed;
<<<<<<< HEAD
  bool b_is_valid;
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}; // r_c_shortest_paths_label

template<class Graph, class Resource_Container>
inline bool operator==
<<<<<<< HEAD
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1, 
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  assert (l1.b_is_valid && l2.b_is_valid);
  return 
=======
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1,
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  return
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    l1.cumulated_resource_consumption == l2.cumulated_resource_consumption;
}

template<class Graph, class Resource_Container>
inline bool operator!=
<<<<<<< HEAD
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1, 
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  assert (l1.b_is_valid && l2.b_is_valid);
  return 
=======
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1,
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  return
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    !( l1 == l2 );
}

template<class Graph, class Resource_Container>
inline bool operator<
<<<<<<< HEAD
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1, 
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  assert (l1.b_is_valid && l2.b_is_valid);
  return 
=======
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1,
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  return
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    l1.cumulated_resource_consumption < l2.cumulated_resource_consumption;
}

template<class Graph, class Resource_Container>
inline bool operator>
<<<<<<< HEAD
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1, 
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  assert (l1.b_is_valid && l2.b_is_valid);
  return 
=======
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1,
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  return
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    l2.cumulated_resource_consumption < l1.cumulated_resource_consumption;
}

template<class Graph, class Resource_Container>
inline bool operator<=
<<<<<<< HEAD
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1, 
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  assert (l1.b_is_valid && l2.b_is_valid);
  return 
=======
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1,
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  return
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    l1 < l2 || l1 == l2;
}

template<class Graph, class Resource_Container>
inline bool operator>=
<<<<<<< HEAD
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1, 
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  assert (l1.b_is_valid && l2.b_is_valid);
  return l2 < l1 || l1 == l2;
}

namespace detail {

// ks_smart_pointer class
// from:
// Kuhlins, S.; Schader, M. (1999):
// Die C++-Standardbibliothek
// Springer, Berlin
// p. 333 f.
template<class T>
class ks_smart_pointer
{
public:
  ks_smart_pointer( T* ptt = 0 ) : pt( ptt ) {}
  ks_smart_pointer( const ks_smart_pointer& other ) : pt( other.pt ) {}
  ks_smart_pointer& operator=( const ks_smart_pointer& other )
    { pt = other.pt; return *this; }
  ~ks_smart_pointer() {}
  T& operator*() const { return *pt; }
  T* operator->() const { return pt; }
  T* get() const { return pt; }
  operator T*() const { return pt; }
  friend bool operator==( const ks_smart_pointer& t, 
                          const ks_smart_pointer& u )
    { return *t.pt == *u.pt; }
  friend bool operator!=( const ks_smart_pointer& t, 
                          const ks_smart_pointer& u )
    { return *t.pt != *u.pt; }
  friend bool operator<( const ks_smart_pointer& t, 
                         const ks_smart_pointer& u )
    { return *t.pt < *u.pt; }
  friend bool operator>( const ks_smart_pointer& t, 
                         const ks_smart_pointer& u )
    { return *t.pt > *u.pt; }
  friend bool operator<=( const ks_smart_pointer& t, 
                          const ks_smart_pointer& u )
    { return *t.pt <= *u.pt; }
  friend bool operator>=( const ks_smart_pointer& t, 
                          const ks_smart_pointer& u )
    { return *t.pt >= *u.pt; }
private:
  T* pt;
}; // ks_smart_pointer


// r_c_shortest_paths_dispatch function (body/implementation)
template<class Graph, 
         class VertexIndexMap, 
         class EdgeIndexMap, 
         class Resource_Container, 
         class Resource_Extension_Function, 
         class Dominance_Function, 
         class Label_Allocator, 
         class Visitor>
void r_c_shortest_paths_dispatch
( const Graph& g, 
  const VertexIndexMap& vertex_index_map, 
  const EdgeIndexMap& /*edge_index_map*/, 
  typename graph_traits<Graph>::vertex_descriptor s, 
  typename graph_traits<Graph>::vertex_descriptor t, 
=======
( const r_c_shortest_paths_label<Graph, Resource_Container>& l1,
  const r_c_shortest_paths_label<Graph, Resource_Container>& l2 )
{
  return l2 < l1 || l1 == l2;
}

template<typename Graph, typename Resource_Container>
inline bool operator<
        ( const boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > &t,
          const boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > &u) {
    return *t < *u;
}

template<typename Graph, typename Resource_Container>
inline bool operator<=( const boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > &t,
                        const boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > &u ) {
    return *t <= *u;
}

template<typename Graph, typename Resource_Container>
inline bool operator>
        (
          const boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > &t,
          const boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > &u ) {
    return *t > *u;
}

template<typename Graph, typename Resource_Container>
inline bool operator>=
        (
          const boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > &t,
          const boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > &u) {
    return *t >= *u;
}

namespace detail {

// r_c_shortest_paths_dispatch function (body/implementation)
template<class Graph,
         class VertexIndexMap,
         class EdgeIndexMap,
         class Resource_Container,
         class Resource_Extension_Function,
         class Dominance_Function,
         class Label_Allocator,
         class Visitor>
void r_c_shortest_paths_dispatch
( const Graph& g,
  const VertexIndexMap& vertex_index_map,
  const EdgeIndexMap& /*edge_index_map*/,
  typename graph_traits<Graph>::vertex_descriptor s,
  typename graph_traits<Graph>::vertex_descriptor t,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  // each inner vector corresponds to a pareto-optimal path
  std::vector
    <std::vector
      <typename graph_traits
<<<<<<< HEAD
        <Graph>::edge_descriptor> >& pareto_optimal_solutions, 
  std::vector
    <Resource_Container>& pareto_optimal_resource_containers, 
  bool b_all_pareto_optimal_solutions, 
  // to initialize the first label/resource container 
  // and to carry the type information
  const Resource_Container& rc, 
  Resource_Extension_Function& ref, 
  Dominance_Function& dominance, 
  // to specify the memory management strategy for the labels
  Label_Allocator /*la*/, 
=======
        <Graph>::edge_descriptor> >& pareto_optimal_solutions,
  std::vector
    <Resource_Container>& pareto_optimal_resource_containers,
  bool b_all_pareto_optimal_solutions,
  // to initialize the first label/resource container
  // and to carry the type information
  const Resource_Container& rc,
  Resource_Extension_Function& ref,
  Dominance_Function& dominance,
  // to specify the memory management strategy for the labels
  Label_Allocator /*la*/,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  Visitor vis )
{
  pareto_optimal_resource_containers.clear();
  pareto_optimal_solutions.clear();

  size_t i_label_num = 0;
<<<<<<< HEAD
  typedef 
    typename 
      Label_Allocator::template rebind
        <r_c_shortest_paths_label
          <Graph, Resource_Container> >::other LAlloc;
  LAlloc l_alloc;
  typedef 
    ks_smart_pointer
      <r_c_shortest_paths_label<Graph, Resource_Container> > Splabel;
  std::priority_queue<Splabel, std::vector<Splabel>, std::greater<Splabel> > 
    unprocessed_labels;

  bool b_feasible = true;
  r_c_shortest_paths_label<Graph, Resource_Container>* first_label = 
    l_alloc.allocate( 1 );
  l_alloc.construct
    ( first_label, 
      r_c_shortest_paths_label
        <Graph, Resource_Container>( i_label_num++, 
                                     rc, 
                                     0, 
                                     typename graph_traits<Graph>::
                                       edge_descriptor(), 
                                     s ) );

  Splabel splabel_first_label = Splabel( first_label );
=======
#if defined(BOOST_NO_CXX11_ALLOCATOR)
  typedef
    typename
      Label_Allocator::template rebind
        <r_c_shortest_paths_label
          <Graph, Resource_Container> >::other LAlloc;
#else
  typedef
     typename
     std::allocator_traits<Label_Allocator>::template rebind_alloc
     <r_c_shortest_paths_label
     <Graph, Resource_Container> > LAlloc;
  typedef std::allocator_traits<LAlloc> LTraits;
#endif
  LAlloc l_alloc;
  typedef
    boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > Splabel;
  std::priority_queue<Splabel, std::vector<Splabel>, std::greater<Splabel> >
    unprocessed_labels;

  bool b_feasible = true;
  Splabel splabel_first_label = boost::allocate_shared<r_c_shortest_paths_label<Graph, Resource_Container> >(
          l_alloc,
          i_label_num++,
          rc,
          boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> >(),
          typename graph_traits<Graph>::edge_descriptor(),
          s );

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  unprocessed_labels.push( splabel_first_label );
  std::vector<std::list<Splabel> > vec_vertex_labels_data( num_vertices( g ) );
  iterator_property_map<typename std::vector<std::list<Splabel> >::iterator,
                        VertexIndexMap>
    vec_vertex_labels(vec_vertex_labels_data.begin(), vertex_index_map);
  vec_vertex_labels[s].push_back( splabel_first_label );
  typedef
<<<<<<< HEAD
    std::vector<typename std::list<Splabel>::iterator> 
=======
    std::vector<typename std::list<Splabel>::iterator>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    vec_last_valid_positions_for_dominance_data_type;
  vec_last_valid_positions_for_dominance_data_type
    vec_last_valid_positions_for_dominance_data( num_vertices( g ) );
  iterator_property_map<
      typename vec_last_valid_positions_for_dominance_data_type::iterator,
      VertexIndexMap>
    vec_last_valid_positions_for_dominance
      (vec_last_valid_positions_for_dominance_data.begin(),
       vertex_index_map);
  BGL_FORALL_VERTICES_T(v, g, Graph) {
    put(vec_last_valid_positions_for_dominance, v, vec_vertex_labels[v].begin());
  }
  std::vector<size_t> vec_last_valid_index_for_dominance_data( num_vertices( g ), 0 );
  iterator_property_map<std::vector<size_t>::iterator, VertexIndexMap>
    vec_last_valid_index_for_dominance
      (vec_last_valid_index_for_dominance_data.begin(), vertex_index_map);
<<<<<<< HEAD
  std::vector<bool> 
=======
  std::vector<bool>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    b_vec_vertex_already_checked_for_dominance_data( num_vertices( g ), false );
  iterator_property_map<std::vector<bool>::iterator, VertexIndexMap>
    b_vec_vertex_already_checked_for_dominance
      (b_vec_vertex_already_checked_for_dominance_data.begin(),
       vertex_index_map);

  while( !unprocessed_labels.empty()  && vis.on_enter_loop(unprocessed_labels, g) )
  {
    Splabel cur_label = unprocessed_labels.top();
<<<<<<< HEAD
    assert (cur_label->b_is_valid);
    unprocessed_labels.pop();
    vis.on_label_popped( *cur_label, g );
    // an Splabel object in unprocessed_labels and the respective Splabel 
    // object in the respective list<Splabel> of vec_vertex_labels share their 
    // embedded r_c_shortest_paths_label object
    // to avoid memory leaks, dominated 
    // r_c_shortest_paths_label objects are marked and deleted when popped 
    // from unprocessed_labels, as they can no longer be deleted at the end of 
    // the function; only the Splabel object in unprocessed_labels still 
    // references the r_c_shortest_paths_label object
    // this is also for efficiency, because the else branch is executed only 
    // if there is a chance that extending the 
    // label leads to new undominated labels, which in turn is possible only 
    // if the label to be extended is undominated
    assert (cur_label->b_is_valid);
=======
    unprocessed_labels.pop();
    vis.on_label_popped( *cur_label, g );
    // an Splabel object in unprocessed_labels and the respective Splabel
    // object in the respective list<Splabel> of vec_vertex_labels share their
    // embedded r_c_shortest_paths_label object
    // to avoid memory leaks, dominated
    // r_c_shortest_paths_label objects are marked and deleted when popped
    // from unprocessed_labels, as they can no longer be deleted at the end of
    // the function; only the Splabel object in unprocessed_labels still
    // references the r_c_shortest_paths_label object
    // this is also for efficiency, because the else branch is executed only
    // if there is a chance that extending the
    // label leads to new undominated labels, which in turn is possible only
    // if the label to be extended is undominated
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    if( !cur_label->b_is_dominated )
    {
      typename boost::graph_traits<Graph>::vertex_descriptor
        i_cur_resident_vertex = cur_label->resident_vertex;
<<<<<<< HEAD
      std::list<Splabel>& list_labels_cur_vertex = 
        get(vec_vertex_labels, i_cur_resident_vertex);
      if( list_labels_cur_vertex.size() >= 2 
          && vec_last_valid_index_for_dominance[i_cur_resident_vertex] 
               < list_labels_cur_vertex.size() )
      {
        typename std::list<Splabel>::iterator outer_iter = 
=======
      std::list<Splabel>& list_labels_cur_vertex =
        get(vec_vertex_labels, i_cur_resident_vertex);
      if( list_labels_cur_vertex.size() >= 2
          && vec_last_valid_index_for_dominance[i_cur_resident_vertex]
               < list_labels_cur_vertex.size() )
      {
        typename std::list<Splabel>::iterator outer_iter =
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
          list_labels_cur_vertex.begin();
        bool b_outer_iter_at_or_beyond_last_valid_pos_for_dominance = false;
        while( outer_iter != list_labels_cur_vertex.end() )
        {
          Splabel cur_outer_splabel = *outer_iter;
<<<<<<< HEAD
          assert (cur_outer_splabel->b_is_valid);
          typename std::list<Splabel>::iterator inner_iter = outer_iter;
          if( !b_outer_iter_at_or_beyond_last_valid_pos_for_dominance 
              && outer_iter == 
=======
          typename std::list<Splabel>::iterator inner_iter = outer_iter;
          if( !b_outer_iter_at_or_beyond_last_valid_pos_for_dominance
              && outer_iter ==
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                   get(vec_last_valid_positions_for_dominance,
                       i_cur_resident_vertex) )
            b_outer_iter_at_or_beyond_last_valid_pos_for_dominance = true;
          if( !get(b_vec_vertex_already_checked_for_dominance, i_cur_resident_vertex)
              || b_outer_iter_at_or_beyond_last_valid_pos_for_dominance )
          {
            ++inner_iter;
          }
          else
          {
<<<<<<< HEAD
            inner_iter = 
=======
            inner_iter =
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
              get(vec_last_valid_positions_for_dominance,
                  i_cur_resident_vertex);
            ++inner_iter;
          }
          bool b_outer_iter_erased = false;
          while( inner_iter != list_labels_cur_vertex.end() )
          {
            Splabel cur_inner_splabel = *inner_iter;
<<<<<<< HEAD
            assert (cur_inner_splabel->b_is_valid);
            if( dominance( cur_outer_splabel->
                             cumulated_resource_consumption, 
=======
            if( dominance( cur_outer_splabel->
                             cumulated_resource_consumption,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                           cur_inner_splabel->
                             cumulated_resource_consumption ) )
            {
              typename std::list<Splabel>::iterator buf = inner_iter;
              ++inner_iter;
              list_labels_cur_vertex.erase( buf );
              if( cur_inner_splabel->b_is_processed )
              {
<<<<<<< HEAD
                cur_inner_splabel->b_is_valid = false;
                l_alloc.destroy( cur_inner_splabel.get() );
                l_alloc.deallocate( cur_inner_splabel.get(), 1 );
=======
                cur_inner_splabel.reset();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
              }
              else
                cur_inner_splabel->b_is_dominated = true;
              continue;
            }
            else
              ++inner_iter;
            if( dominance( cur_inner_splabel->
<<<<<<< HEAD
                             cumulated_resource_consumption, 
=======
                             cumulated_resource_consumption,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                           cur_outer_splabel->
                             cumulated_resource_consumption ) )
            {
              typename std::list<Splabel>::iterator buf = outer_iter;
              ++outer_iter;
              list_labels_cur_vertex.erase( buf );
              b_outer_iter_erased = true;
<<<<<<< HEAD
              assert (cur_outer_splabel->b_is_valid);
              if( cur_outer_splabel->b_is_processed )
              {
                cur_outer_splabel->b_is_valid = false;
                l_alloc.destroy( cur_outer_splabel.get() );
                l_alloc.deallocate( cur_outer_splabel.get(), 1 );
=======
              if( cur_outer_splabel->b_is_processed )
              {
                cur_outer_splabel.reset();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
              }
              else
                cur_outer_splabel->b_is_dominated = true;
              break;
            }
          }
          if( !b_outer_iter_erased )
            ++outer_iter;
        }
        if( list_labels_cur_vertex.size() > 1 )
          put(vec_last_valid_positions_for_dominance, i_cur_resident_vertex,
            (--(list_labels_cur_vertex.end())));
        else
          put(vec_last_valid_positions_for_dominance, i_cur_resident_vertex,
            list_labels_cur_vertex.begin());
        put(b_vec_vertex_already_checked_for_dominance,
            i_cur_resident_vertex, true);
        put(vec_last_valid_index_for_dominance, i_cur_resident_vertex,
          list_labels_cur_vertex.size() - 1);
      }
    }
<<<<<<< HEAD
    assert (b_all_pareto_optimal_solutions || cur_label->b_is_valid);
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    if( !b_all_pareto_optimal_solutions && cur_label->resident_vertex == t )
    {
      // the devil don't sleep
      if( cur_label->b_is_dominated )
      {
<<<<<<< HEAD
        cur_label->b_is_valid = false;
        l_alloc.destroy( cur_label.get() );
        l_alloc.deallocate( cur_label.get(), 1 );
=======
        cur_label.reset();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      }
      while( unprocessed_labels.size() )
      {
        Splabel l = unprocessed_labels.top();
<<<<<<< HEAD
        assert (l->b_is_valid);
        unprocessed_labels.pop();
        // delete only dominated labels, because nondominated labels are 
        // deleted at the end of the function
        if( l->b_is_dominated )
        {
          l->b_is_valid = false;
          l_alloc.destroy( l.get() );
          l_alloc.deallocate( l.get(), 1 );
=======
        unprocessed_labels.pop();
        // delete only dominated labels, because nondominated labels are
        // deleted at the end of the function
        if( l->b_is_dominated )
        {
          l.reset();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }
      }
      break;
    }
    if( !cur_label->b_is_dominated )
    {
      cur_label->b_is_processed = true;
      vis.on_label_not_dominated( *cur_label, g );
<<<<<<< HEAD
      typename graph_traits<Graph>::vertex_descriptor cur_vertex = 
        cur_label->resident_vertex;
      typename graph_traits<Graph>::out_edge_iterator oei, oei_end;
      for( boost::tie( oei, oei_end ) = out_edges( cur_vertex, g ); 
           oei != oei_end; 
           ++oei )
      {
        b_feasible = true;
        r_c_shortest_paths_label<Graph, Resource_Container>* new_label = 
          l_alloc.allocate( 1 );
        l_alloc.construct( new_label, 
                           r_c_shortest_paths_label
                             <Graph, Resource_Container>
                               ( i_label_num++, 
                                 cur_label->cumulated_resource_consumption, 
                                 cur_label.get(), 
                                 *oei, 
                                 target( *oei, g ) ) );
        b_feasible = 
          ref( g, 
               new_label->cumulated_resource_consumption, 
               new_label->p_pred_label->cumulated_resource_consumption, 
=======
      typename graph_traits<Graph>::vertex_descriptor cur_vertex =
        cur_label->resident_vertex;
      typename graph_traits<Graph>::out_edge_iterator oei, oei_end;
      for( boost::tie( oei, oei_end ) = out_edges( cur_vertex, g );
           oei != oei_end;
           ++oei )
      {
        b_feasible = true;
        Splabel new_label = boost::allocate_shared<r_c_shortest_paths_label<Graph, Resource_Container> >(
                l_alloc,
                i_label_num++,
                cur_label->cumulated_resource_consumption,
                cur_label,
                *oei,
                target( *oei, g ) );
        b_feasible =
          ref( g,
               new_label->cumulated_resource_consumption,
               new_label->p_pred_label->cumulated_resource_consumption,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
               new_label->pred_edge );

        if( !b_feasible )
        {
          vis.on_label_not_feasible( *new_label, g );
<<<<<<< HEAD
          new_label->b_is_valid = false;
          l_alloc.destroy( new_label );
          l_alloc.deallocate( new_label, 1 );
        }
        else
        {
          const r_c_shortest_paths_label<Graph, Resource_Container>& 
            ref_new_label = *new_label;
          vis.on_label_feasible( ref_new_label, g );
          Splabel new_sp_label( new_label );
          vec_vertex_labels[new_sp_label->resident_vertex].
            push_back( new_sp_label );
          unprocessed_labels.push( new_sp_label );
=======
          new_label.reset();
        }
        else
        {
          vis.on_label_feasible( *new_label, g );
          vec_vertex_labels[new_label->resident_vertex].
            push_back( new_label );
          unprocessed_labels.push( new_label );
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }
      }
    }
    else
    {
<<<<<<< HEAD
      assert (cur_label->b_is_valid);
      vis.on_label_dominated( *cur_label, g );
      cur_label->b_is_valid = false;
      l_alloc.destroy( cur_label.get() );
      l_alloc.deallocate( cur_label.get(), 1 );
=======
      vis.on_label_dominated( *cur_label, g );
      cur_label.reset();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
  }
  std::list<Splabel> dsplabels = get(vec_vertex_labels, t);
  typename std::list<Splabel>::const_iterator csi = dsplabels.begin();
  typename std::list<Splabel>::const_iterator csi_end = dsplabels.end();
  // if d could be reached from o
  if( !dsplabels.empty() )
  {
    for( ; csi != csi_end; ++csi )
    {
<<<<<<< HEAD
      std::vector<typename graph_traits<Graph>::edge_descriptor> 
        cur_pareto_optimal_path;
      const r_c_shortest_paths_label<Graph, Resource_Container>* p_cur_label = 
        (*csi).get();
      assert (p_cur_label->b_is_valid);
=======
      std::vector<typename graph_traits<Graph>::edge_descriptor>
        cur_pareto_optimal_path;
      boost::shared_ptr<r_c_shortest_paths_label<Graph, Resource_Container> > p_cur_label = *csi;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      pareto_optimal_resource_containers.
        push_back( p_cur_label->cumulated_resource_consumption );
      while( p_cur_label->num != 0 )
      {
        cur_pareto_optimal_path.push_back( p_cur_label->pred_edge );
        p_cur_label = p_cur_label->p_pred_label;
<<<<<<< HEAD
        assert (p_cur_label->b_is_valid);
=======

        // assertion b_is_valid beyond this point is not correct if the domination function
        // requires resource levels to be strictly greater than existing values
        //
        // Example
        // Customers
        // id   min_arrival   max_departure
        //  2             0             974
        //  3             0             972
        //  4             0             964
        //  5           678             801
        //
        // Path A: 2-3-4-5 (times: 0-16-49-84-678)
        // Path B: 3-2-4-5 (times: 0-18-51-62-678)
        // The partial path 3-2-4 dominates the other partial path 2-3-4,
        // though the path 3-2-4-5 does not strictly dominate the path 2-3-4-5
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      }
      pareto_optimal_solutions.push_back( cur_pareto_optimal_path );
      if( !b_all_pareto_optimal_solutions )
        break;
    }
  }

  BGL_FORALL_VERTICES_T(i, g, Graph) {
<<<<<<< HEAD
    const std::list<Splabel>& list_labels_cur_vertex = vec_vertex_labels[i];
    csi_end = list_labels_cur_vertex.end();
    for( csi = list_labels_cur_vertex.begin(); csi != csi_end; ++csi )
    {
      assert ((*csi)->b_is_valid);
      (*csi)->b_is_valid = false;
      l_alloc.destroy( (*csi).get() );
      l_alloc.deallocate( (*csi).get(), 1 );
=======
    std::list<Splabel>& list_labels_cur_vertex = vec_vertex_labels[i];
    typename std::list<Splabel>::iterator si = list_labels_cur_vertex.begin();
    const typename std::list<Splabel>::iterator si_end = list_labels_cur_vertex.end();
    for(; si != si_end; ++si )
    {
      (*si).reset();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
  }
} // r_c_shortest_paths_dispatch

} // detail

// default_r_c_shortest_paths_visitor struct
struct default_r_c_shortest_paths_visitor
{
  template<class Label, class Graph>
  void on_label_popped( const Label&, const Graph& ) {}
  template<class Label, class Graph>
  void on_label_feasible( const Label&, const Graph& ) {}
  template<class Label, class Graph>
  void on_label_not_feasible( const Label&, const Graph& ) {}
  template<class Label, class Graph>
  void on_label_dominated( const Label&, const Graph& ) {}
  template<class Label, class Graph>
  void on_label_not_dominated( const Label&, const Graph& ) {}
<<<<<<< HEAD
  template<class Queue, class Graph>             
=======
  template<class Queue, class Graph>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  bool on_enter_loop(const Queue& queue, const Graph& graph) {return true;}
}; // default_r_c_shortest_paths_visitor


// default_r_c_shortest_paths_allocator
<<<<<<< HEAD
typedef 
=======
typedef
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  std::allocator<int> default_r_c_shortest_paths_allocator;
// default_r_c_shortest_paths_allocator


// r_c_shortest_paths functions (handle/interface)
// first overload:
// - return all pareto-optimal solutions
// - specify Label_Allocator and Visitor arguments
<<<<<<< HEAD
template<class Graph, 
         class VertexIndexMap, 
         class EdgeIndexMap, 
         class Resource_Container, 
         class Resource_Extension_Function, 
         class Dominance_Function, 
         class Label_Allocator, 
         class Visitor>
void r_c_shortest_paths
( const Graph& g, 
  const VertexIndexMap& vertex_index_map, 
  const EdgeIndexMap& edge_index_map, 
  typename graph_traits<Graph>::vertex_descriptor s, 
  typename graph_traits<Graph>::vertex_descriptor t, 
  // each inner vector corresponds to a pareto-optimal path
  std::vector<std::vector<typename graph_traits<Graph>::edge_descriptor> >& 
    pareto_optimal_solutions, 
  std::vector<Resource_Container>& pareto_optimal_resource_containers, 
  // to initialize the first label/resource container 
  // and to carry the type information
  const Resource_Container& rc, 
  const Resource_Extension_Function& ref, 
  const Dominance_Function& dominance, 
  // to specify the memory management strategy for the labels
  Label_Allocator la, 
  Visitor vis )
{
  r_c_shortest_paths_dispatch( g, 
                               vertex_index_map, 
                               edge_index_map, 
                               s, 
                               t, 
                               pareto_optimal_solutions, 
                               pareto_optimal_resource_containers, 
                               true, 
                               rc, 
                               ref, 
                               dominance, 
                               la, 
=======
template<class Graph,
         class VertexIndexMap,
         class EdgeIndexMap,
         class Resource_Container,
         class Resource_Extension_Function,
         class Dominance_Function,
         class Label_Allocator,
         class Visitor>
void r_c_shortest_paths
( const Graph& g,
  const VertexIndexMap& vertex_index_map,
  const EdgeIndexMap& edge_index_map,
  typename graph_traits<Graph>::vertex_descriptor s,
  typename graph_traits<Graph>::vertex_descriptor t,
  // each inner vector corresponds to a pareto-optimal path
  std::vector<std::vector<typename graph_traits<Graph>::edge_descriptor> >&
    pareto_optimal_solutions,
  std::vector<Resource_Container>& pareto_optimal_resource_containers,
  // to initialize the first label/resource container
  // and to carry the type information
  const Resource_Container& rc,
  const Resource_Extension_Function& ref,
  const Dominance_Function& dominance,
  // to specify the memory management strategy for the labels
  Label_Allocator la,
  Visitor vis )
{
  r_c_shortest_paths_dispatch( g,
                               vertex_index_map,
                               edge_index_map,
                               s,
                               t,
                               pareto_optimal_solutions,
                               pareto_optimal_resource_containers,
                               true,
                               rc,
                               ref,
                               dominance,
                               la,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                               vis );
}

// second overload:
// - return only one pareto-optimal solution
// - specify Label_Allocator and Visitor arguments
<<<<<<< HEAD
template<class Graph, 
         class VertexIndexMap, 
         class EdgeIndexMap, 
         class Resource_Container, 
         class Resource_Extension_Function, 
         class Dominance_Function, 
         class Label_Allocator, 
         class Visitor>
void r_c_shortest_paths
( const Graph& g, 
  const VertexIndexMap& vertex_index_map, 
  const EdgeIndexMap& edge_index_map, 
  typename graph_traits<Graph>::vertex_descriptor s, 
  typename graph_traits<Graph>::vertex_descriptor t, 
  std::vector<typename graph_traits<Graph>::edge_descriptor>& 
    pareto_optimal_solution, 
  Resource_Container& pareto_optimal_resource_container, 
  // to initialize the first label/resource container 
  // and to carry the type information
  const Resource_Container& rc, 
  const Resource_Extension_Function& ref, 
  const Dominance_Function& dominance, 
  // to specify the memory management strategy for the labels
  Label_Allocator la, 
  Visitor vis )
{
  // each inner vector corresponds to a pareto-optimal path
  std::vector<std::vector<typename graph_traits<Graph>::edge_descriptor> > 
    pareto_optimal_solutions;
  std::vector<Resource_Container> pareto_optimal_resource_containers;
  r_c_shortest_paths_dispatch( g, 
                               vertex_index_map, 
                               edge_index_map, 
                               s, 
                               t, 
                               pareto_optimal_solutions, 
                               pareto_optimal_resource_containers, 
                               false, 
                               rc, 
                               ref, 
                               dominance, 
                               la, 
=======
template<class Graph,
         class VertexIndexMap,
         class EdgeIndexMap,
         class Resource_Container,
         class Resource_Extension_Function,
         class Dominance_Function,
         class Label_Allocator,
         class Visitor>
void r_c_shortest_paths
( const Graph& g,
  const VertexIndexMap& vertex_index_map,
  const EdgeIndexMap& edge_index_map,
  typename graph_traits<Graph>::vertex_descriptor s,
  typename graph_traits<Graph>::vertex_descriptor t,
  std::vector<typename graph_traits<Graph>::edge_descriptor>&
    pareto_optimal_solution,
  Resource_Container& pareto_optimal_resource_container,
  // to initialize the first label/resource container
  // and to carry the type information
  const Resource_Container& rc,
  const Resource_Extension_Function& ref,
  const Dominance_Function& dominance,
  // to specify the memory management strategy for the labels
  Label_Allocator la,
  Visitor vis )
{
  // each inner vector corresponds to a pareto-optimal path
  std::vector<std::vector<typename graph_traits<Graph>::edge_descriptor> >
    pareto_optimal_solutions;
  std::vector<Resource_Container> pareto_optimal_resource_containers;
  r_c_shortest_paths_dispatch( g,
                               vertex_index_map,
                               edge_index_map,
                               s,
                               t,
                               pareto_optimal_solutions,
                               pareto_optimal_resource_containers,
                               false,
                               rc,
                               ref,
                               dominance,
                               la,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                               vis );
  if (!pareto_optimal_solutions.empty()) {
    pareto_optimal_solution = pareto_optimal_solutions[0];
    pareto_optimal_resource_container = pareto_optimal_resource_containers[0];
  }
}

// third overload:
// - return all pareto-optimal solutions
// - use default Label_Allocator and Visitor
<<<<<<< HEAD
template<class Graph, 
         class VertexIndexMap, 
         class EdgeIndexMap, 
         class Resource_Container, 
         class Resource_Extension_Function, 
         class Dominance_Function>
void r_c_shortest_paths
( const Graph& g, 
  const VertexIndexMap& vertex_index_map, 
  const EdgeIndexMap& edge_index_map, 
  typename graph_traits<Graph>::vertex_descriptor s, 
  typename graph_traits<Graph>::vertex_descriptor t, 
  // each inner vector corresponds to a pareto-optimal path
  std::vector<std::vector<typename graph_traits<Graph>::edge_descriptor> >& 
    pareto_optimal_solutions, 
  std::vector<Resource_Container>& pareto_optimal_resource_containers, 
  // to initialize the first label/resource container 
  // and to carry the type information
  const Resource_Container& rc, 
  const Resource_Extension_Function& ref, 
  const Dominance_Function& dominance )
{
  r_c_shortest_paths_dispatch( g, 
                               vertex_index_map, 
                               edge_index_map, 
                               s, 
                               t, 
                               pareto_optimal_solutions, 
                               pareto_optimal_resource_containers, 
                               true, 
                               rc, 
                               ref, 
                               dominance, 
                               default_r_c_shortest_paths_allocator(), 
=======
template<class Graph,
         class VertexIndexMap,
         class EdgeIndexMap,
         class Resource_Container,
         class Resource_Extension_Function,
         class Dominance_Function>
void r_c_shortest_paths
( const Graph& g,
  const VertexIndexMap& vertex_index_map,
  const EdgeIndexMap& edge_index_map,
  typename graph_traits<Graph>::vertex_descriptor s,
  typename graph_traits<Graph>::vertex_descriptor t,
  // each inner vector corresponds to a pareto-optimal path
  std::vector<std::vector<typename graph_traits<Graph>::edge_descriptor> >&
    pareto_optimal_solutions,
  std::vector<Resource_Container>& pareto_optimal_resource_containers,
  // to initialize the first label/resource container
  // and to carry the type information
  const Resource_Container& rc,
  const Resource_Extension_Function& ref,
  const Dominance_Function& dominance )
{
  r_c_shortest_paths_dispatch( g,
                               vertex_index_map,
                               edge_index_map,
                               s,
                               t,
                               pareto_optimal_solutions,
                               pareto_optimal_resource_containers,
                               true,
                               rc,
                               ref,
                               dominance,
                               default_r_c_shortest_paths_allocator(),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                               default_r_c_shortest_paths_visitor() );
}

// fourth overload:
// - return only one pareto-optimal solution
// - use default Label_Allocator and Visitor
<<<<<<< HEAD
template<class Graph, 
         class VertexIndexMap, 
         class EdgeIndexMap, 
         class Resource_Container, 
         class Resource_Extension_Function, 
         class Dominance_Function>
void r_c_shortest_paths
( const Graph& g, 
  const VertexIndexMap& vertex_index_map, 
  const EdgeIndexMap& edge_index_map, 
  typename graph_traits<Graph>::vertex_descriptor s, 
  typename graph_traits<Graph>::vertex_descriptor t, 
  std::vector<typename graph_traits<Graph>::edge_descriptor>& 
    pareto_optimal_solution, 
  Resource_Container& pareto_optimal_resource_container, 
  // to initialize the first label/resource container 
  // and to carry the type information
  const Resource_Container& rc, 
  const Resource_Extension_Function& ref, 
  const Dominance_Function& dominance )
{
  // each inner vector corresponds to a pareto-optimal path
  std::vector<std::vector<typename graph_traits<Graph>::edge_descriptor> > 
    pareto_optimal_solutions;
  std::vector<Resource_Container> pareto_optimal_resource_containers;
  r_c_shortest_paths_dispatch( g, 
                               vertex_index_map, 
                               edge_index_map, 
                               s, 
                               t, 
                               pareto_optimal_solutions, 
                               pareto_optimal_resource_containers, 
                               false, 
                               rc, 
                               ref, 
                               dominance, 
                               default_r_c_shortest_paths_allocator(), 
=======
template<class Graph,
         class VertexIndexMap,
         class EdgeIndexMap,
         class Resource_Container,
         class Resource_Extension_Function,
         class Dominance_Function>
void r_c_shortest_paths
( const Graph& g,
  const VertexIndexMap& vertex_index_map,
  const EdgeIndexMap& edge_index_map,
  typename graph_traits<Graph>::vertex_descriptor s,
  typename graph_traits<Graph>::vertex_descriptor t,
  std::vector<typename graph_traits<Graph>::edge_descriptor>&
    pareto_optimal_solution,
  Resource_Container& pareto_optimal_resource_container,
  // to initialize the first label/resource container
  // and to carry the type information
  const Resource_Container& rc,
  const Resource_Extension_Function& ref,
  const Dominance_Function& dominance )
{
  // each inner vector corresponds to a pareto-optimal path
  std::vector<std::vector<typename graph_traits<Graph>::edge_descriptor> >
    pareto_optimal_solutions;
  std::vector<Resource_Container> pareto_optimal_resource_containers;
  r_c_shortest_paths_dispatch( g,
                               vertex_index_map,
                               edge_index_map,
                               s,
                               t,
                               pareto_optimal_solutions,
                               pareto_optimal_resource_containers,
                               false,
                               rc,
                               ref,
                               dominance,
                               default_r_c_shortest_paths_allocator(),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                               default_r_c_shortest_paths_visitor() );
  if (!pareto_optimal_solutions.empty()) {
    pareto_optimal_solution = pareto_optimal_solutions[0];
    pareto_optimal_resource_container = pareto_optimal_resource_containers[0];
  }
}
// r_c_shortest_paths


// check_r_c_path function
<<<<<<< HEAD
template<class Graph, 
         class Resource_Container, 
         class Resource_Extension_Function>
void check_r_c_path( const Graph& g, 
                     const std::vector
                       <typename graph_traits
                         <Graph>::edge_descriptor>& ed_vec_path, 
                     const Resource_Container& initial_resource_levels, 
                     // if true, computed accumulated final resource levels must 
                     // be equal to desired_final_resource_levels
                     // if false, computed accumulated final resource levels must 
                     // be less than or equal to desired_final_resource_levels
                     bool b_result_must_be_equal_to_desired_final_resource_levels, 
                     const Resource_Container& desired_final_resource_levels, 
                     Resource_Container& actual_final_resource_levels, 
                     const Resource_Extension_Function& ref, 
                     bool& b_is_a_path_at_all, 
                     bool& b_feasible, 
                     bool& b_correctly_extended, 
                     typename graph_traits<Graph>::edge_descriptor& 
=======
template<class Graph,
         class Resource_Container,
         class Resource_Extension_Function>
void check_r_c_path( const Graph& g,
                     const std::vector
                       <typename graph_traits
                         <Graph>::edge_descriptor>& ed_vec_path,
                     const Resource_Container& initial_resource_levels,
                     // if true, computed accumulated final resource levels must
                     // be equal to desired_final_resource_levels
                     // if false, computed accumulated final resource levels must
                     // be less than or equal to desired_final_resource_levels
                     bool b_result_must_be_equal_to_desired_final_resource_levels,
                     const Resource_Container& desired_final_resource_levels,
                     Resource_Container& actual_final_resource_levels,
                     const Resource_Extension_Function& ref,
                     bool& b_is_a_path_at_all,
                     bool& b_feasible,
                     bool& b_correctly_extended,
                     typename graph_traits<Graph>::edge_descriptor&
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                       ed_last_extended_arc )
{
  size_t i_size_ed_vec_path = ed_vec_path.size();
  std::vector<typename graph_traits<Graph>::edge_descriptor> buf_path;
  if( i_size_ed_vec_path == 0 )
    b_feasible = true;
  else
  {
<<<<<<< HEAD
    if( i_size_ed_vec_path == 1 
=======
    if( i_size_ed_vec_path == 1
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        || target( ed_vec_path[0], g ) == source( ed_vec_path[1], g ) )
      buf_path = ed_vec_path;
    else
      for( size_t i = i_size_ed_vec_path ; i > 0; --i )
        buf_path.push_back( ed_vec_path[i - 1] );
    for( size_t i = 0; i < i_size_ed_vec_path - 1; ++i )
    {
      if( target( buf_path[i], g ) != source( buf_path[i + 1], g ) )
      {
        b_is_a_path_at_all = false;
        b_feasible = false;
        b_correctly_extended = false;
        return;
      }
    }
  }
  b_is_a_path_at_all = true;
  b_feasible = true;
  b_correctly_extended = false;
  Resource_Container current_resource_levels = initial_resource_levels;
  actual_final_resource_levels = current_resource_levels;
  for( size_t i = 0; i < i_size_ed_vec_path; ++i )
  {
    ed_last_extended_arc = buf_path[i];
<<<<<<< HEAD
    b_feasible = ref( g, 
                      actual_final_resource_levels, 
                      current_resource_levels, 
=======
    b_feasible = ref( g,
                      actual_final_resource_levels,
                      current_resource_levels,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                      buf_path[i] );
    current_resource_levels = actual_final_resource_levels;
    if( !b_feasible )
      return;
  }
  if( b_result_must_be_equal_to_desired_final_resource_levels )
<<<<<<< HEAD
    b_correctly_extended = 
     actual_final_resource_levels == desired_final_resource_levels ? 
       true : false;
  else
  {
    if( actual_final_resource_levels < desired_final_resource_levels 
=======
    b_correctly_extended =
     actual_final_resource_levels == desired_final_resource_levels ?
       true : false;
  else
  {
    if( actual_final_resource_levels < desired_final_resource_levels
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        || actual_final_resource_levels == desired_final_resource_levels )
      b_correctly_extended = true;
  }
} // check_path

} // namespace

#endif // BOOST_GRAPH_R_C_SHORTEST_PATHS_HPP
