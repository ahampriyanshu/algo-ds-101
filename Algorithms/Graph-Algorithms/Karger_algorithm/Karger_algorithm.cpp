#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <math.h>
#include <cassert>

namespace std {   };
using namespace std;

class karger_graph
{
public:
   void   set(size_t r, size_t c, size_t d) {   _data[(r * _rc) + c] = d;   return;   };
   size_t get(size_t r, size_t c) const {   return _data[(r * _rc) + c];   };

   void   set_size(size_t rc) {   _rc = rc;   _data.resize(_rc * _rc);   return;   };
   size_t get_size() const {   return _rc;   };

   size_t count_vertices() const;
   size_t count_edges() const;
   karger_graph& remove_self_loops();
   karger_graph& merge_vertices(size_t u, size_t v);

private:
   size_t _rc;
   vector<size_t> _data;
};

size_t karger_graph::count_vertices() const
{
   size_t n = 0;

   for (size_t i = 0; i < _rc; ++i)
   {
      size_t k = 0;
      for (size_t j = 0; j < _rc; ++j)
      {
         k = k + get(i, j);
      }

      if (k > 0)
      {
         ++n;
      }
   }

   return n;
}

size_t karger_graph::count_edges() const
{
   size_t n = 0;

   for (size_t i = 0; i < _rc; ++i)
   {
      for (size_t j = 0; j < _rc; ++j)
      {
         n = n + get(i, j);
      }
   }

   return n;
}

karger_graph& karger_graph::remove_self_loops()
{
   for (size_t i = 0; i < _rc; ++i)
   {
      set(i, i, 0);
   }

   return *this;
}

karger_graph& karger_graph::merge_vertices(size_t u, size_t v)
{
   if (u < _rc && v < _rc)
   {
      for (size_t i = 0; i < _rc; ++i)
      {
         size_t e = get(v, i);
         set(v, i, 0);

         size_t n = e + get(u, i);
         set(u, i, n);

         e = get(i, v);
         set(i, v, 0);

         n = e + get(i, u);
         set(i, u, n);
      }
   }

   return *this;
}

void random_contraction_algorithm(karger_graph& km)
{
   km.remove_self_loops();

   while (km.count_vertices() > 2)
   {
   /* Pick an edge. */
      size_t random_vertex_u = 0, random_vertex_v = 0;

      do
      {
         random_vertex_u = rand() % km.get_size();
         random_vertex_v = rand() % km.get_size();
      }
      while (km.get(random_vertex_u, random_vertex_v) == 0);

      assert(random_vertex_u != random_vertex_v);

   /* Merge both vertices. */
      km.merge_vertices(random_vertex_u, random_vertex_v);

   /* Remove self-loops. */
      km.remove_self_loops();
   }

   return;
}

istream& operator>>(istream& is, karger_graph& km)
{
   size_t dim = 0;
   is >> dim;
   km.set_size(dim);

   for (size_t i = 0; i < dim; ++i)
   {
      for (size_t j = 0; j < dim; ++j)
      {
         size_t k = 0;
         is >> k;
         if (is.good() != false)
         {
            km.set(i, j, k);
         }
      }
   }

   return is;
}

ostream& operator<<(ostream& os, const karger_graph& km)
{
   size_t dim = km.get_size();

   os << dim << " " << endl;

   for (size_t i = 0; i < dim; ++i)
   {
      for (size_t j = 0; j < dim; ++j)
      {
         os << km.get(i, j) << " ";
      }

      os << endl;
   }

   return os;
}

int main(int argc, char* argv[])
{
   karger_graph graph, minimum_graph;
   graph.set_size(0);
   minimum_graph.set_size(0);

   if (argc > 1)
   {
      ifstream ifs;
      ifs.open(argv[1]);
      ifs >> graph;
      ifs.close();
   }

   if (graph.get_size() > 0)
   {
      cout << "Input vertex count: " << graph.count_vertices() << endl;
      cout << "Input edge count: " << (graph.count_edges() >> 1) << endl;

      srand((unsigned int) time(NULL));

      size_t n = graph.count_vertices();
      float ln = log((float) n);
      size_t runs = n * n * ln, minimum_cut = UINT_MAX;

      for (size_t i = 0; i < runs; ++i)
      {
         karger_graph copy = graph;
         random_contraction_algorithm(copy);

         size_t cut = copy.count_edges();
         assert((cut % 2) == 0);

         if (cut < minimum_cut)
         {
            minimum_cut = cut;
            minimum_graph = copy;
         }
      }

      cout << "Runs: " << runs << endl;
      cout << "Output vertex count: " << minimum_graph.count_vertices() << endl;
      cout << "Output edge count: " << (minimum_graph.count_edges() >> 1) << endl;

      assert(minimum_cut == 6);

      if (argc > 2)
      {
         ofstream ofs;
         ofs.open(argv[2]);
         ofs << minimum_graph;
         ofs.close();
      }
   }

   cin.get();

   return 0;
}
