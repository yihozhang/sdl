
#include "souffle/CompiledSouffle.h"

extern "C" {}

namespace souffle {
using namespace ram;
struct t_btree_2__1_0__0_1__1__2__3 {
  using t_tuple = Tuple<RamDomain, 2>;
  using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1, 0>>;
  t_ind_0 ind_0;
  using t_ind_1 = btree_set<t_tuple, index_utils::comparator<0, 1>>;
  t_ind_1 ind_1;
  using iterator = t_ind_0::iterator;
  struct context {
    t_ind_0::operation_hints hints_0;
    t_ind_1::operation_hints hints_1;
  };
  context createContext() { return context(); }
  bool insert(const t_tuple& t) {
    context h;
    return insert(t, h);
  }
  bool insert(const t_tuple& t, context& h) {
    if (ind_0.insert(t, h.hints_0)) {
      ind_1.insert(t, h.hints_1);
      return true;
    } else
      return false;
  }
  bool insert(const RamDomain* ramDomain) {
    RamDomain data[2];
    std::copy(ramDomain, ramDomain + 2, data);
    const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
    context h;
    return insert(tuple, h);
  }
  bool insert(RamDomain a0, RamDomain a1) {
    RamDomain data[2] = {a0, a1};
    return insert(data);
  }
  template <typename T>
  void insertAll(T& other) {
    for (auto const& cur : other) {
      insert(cur);
    }
  }
  void insertAll(t_btree_2__1_0__0_1__1__2__3& other) {
    ind_0.insertAll(other.ind_0);
    ind_1.insertAll(other.ind_1);
  }
  bool contains(const t_tuple& t, context& h) const {
    return ind_0.contains(t, h.hints_0);
  }
  bool contains(const t_tuple& t) const {
    context h;
    return contains(t, h);
  }
  std::size_t size() const { return ind_0.size(); }
  iterator find(const t_tuple& t, context& h) const {
    return ind_0.find(t, h.hints_0);
  }
  iterator find(const t_tuple& t) const {
    context h;
    return find(t, h);
  }
  range<iterator> equalRange_0(const t_tuple& t, context& h) const {
    return range<iterator>(ind_0.begin(), ind_0.end());
  }
  range<iterator> equalRange_0(const t_tuple& t) const {
    return range<iterator>(ind_0.begin(), ind_0.end());
  }
  range<t_ind_1::iterator> equalRange_1(const t_tuple& t, context& h) const {
    t_tuple low(t);
    t_tuple high(t);
    low[1] = MIN_RAM_DOMAIN;
    high[1] = MAX_RAM_DOMAIN;
    return make_range(ind_1.lower_bound(low, h.hints_1),
                      ind_1.upper_bound(high, h.hints_1));
  }
  range<t_ind_1::iterator> equalRange_1(const t_tuple& t) const {
    context h;
    return equalRange_1(t, h);
  }
  range<t_ind_0::iterator> equalRange_2(const t_tuple& t, context& h) const {
    t_tuple low(t);
    t_tuple high(t);
    low[0] = MIN_RAM_DOMAIN;
    high[0] = MAX_RAM_DOMAIN;
    return make_range(ind_0.lower_bound(low, h.hints_0),
                      ind_0.upper_bound(high, h.hints_0));
  }
  range<t_ind_0::iterator> equalRange_2(const t_tuple& t) const {
    context h;
    return equalRange_2(t, h);
  }
  range<t_ind_1::iterator> equalRange_3(const t_tuple& t, context& h) const {
    auto pos = ind_1.find(t, h.hints_1);
    auto fin = ind_1.end();
    if (pos != fin) {
      fin = pos;
      ++fin;
    }
    return make_range(pos, fin);
  }
  range<t_ind_1::iterator> equalRange_3(const t_tuple& t) const {
    context h;
    return equalRange_3(t, h);
  }
  bool empty() const { return ind_0.empty(); }
  std::vector<range<iterator>> partition() const {
    return ind_0.getChunks(400);
  }
  void purge() {
    ind_0.clear();
    ind_1.clear();
  }
  iterator begin() const { return ind_0.begin(); }
  iterator end() const { return ind_0.end(); }
  void printHintStatistics(std::ostream& o, const std::string prefix) const {
    const auto& stats_0 = ind_0.getHintStatistics();
    o << prefix << "arity 2 direct b-tree index [1,0]: (hits/misses/total)\n";
    o << prefix << "Insert: " << stats_0.inserts.getHits() << "/"
      << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses()
      << "\n";
    o << prefix << "Contains: " << stats_0.contains.getHits() << "/"
      << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses()
      << "\n";
    o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/"
      << stats_0.lower_bound.getMisses() << "/"
      << stats_0.lower_bound.getAccesses() << "\n";
    o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/"
      << stats_0.upper_bound.getMisses() << "/"
      << stats_0.upper_bound.getAccesses() << "\n";
    const auto& stats_1 = ind_1.getHintStatistics();
    o << prefix << "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
    o << prefix << "Insert: " << stats_1.inserts.getHits() << "/"
      << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses()
      << "\n";
    o << prefix << "Contains: " << stats_1.contains.getHits() << "/"
      << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses()
      << "\n";
    o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/"
      << stats_1.lower_bound.getMisses() << "/"
      << stats_1.lower_bound.getAccesses() << "\n";
    o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/"
      << stats_1.upper_bound.getMisses() << "/"
      << stats_1.upper_bound.getAccesses() << "\n";
  }
};
struct t_btree_2__1_0__2__3 {
  using t_tuple = Tuple<RamDomain, 2>;
  using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1, 0>>;
  t_ind_0 ind_0;
  using iterator = t_ind_0::iterator;
  struct context {
    t_ind_0::operation_hints hints_0;
  };
  context createContext() { return context(); }
  bool insert(const t_tuple& t) {
    context h;
    return insert(t, h);
  }
  bool insert(const t_tuple& t, context& h) {
    if (ind_0.insert(t, h.hints_0)) {
      return true;
    } else
      return false;
  }
  bool insert(const RamDomain* ramDomain) {
    RamDomain data[2];
    std::copy(ramDomain, ramDomain + 2, data);
    const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
    context h;
    return insert(tuple, h);
  }
  bool insert(RamDomain a0, RamDomain a1) {
    RamDomain data[2] = {a0, a1};
    return insert(data);
  }
  template <typename T>
  void insertAll(T& other) {
    for (auto const& cur : other) {
      insert(cur);
    }
  }
  void insertAll(t_btree_2__1_0__2__3& other) { ind_0.insertAll(other.ind_0); }
  bool contains(const t_tuple& t, context& h) const {
    return ind_0.contains(t, h.hints_0);
  }
  bool contains(const t_tuple& t) const {
    context h;
    return contains(t, h);
  }
  std::size_t size() const { return ind_0.size(); }
  iterator find(const t_tuple& t, context& h) const {
    return ind_0.find(t, h.hints_0);
  }
  iterator find(const t_tuple& t) const {
    context h;
    return find(t, h);
  }
  range<iterator> equalRange_0(const t_tuple& t, context& h) const {
    return range<iterator>(ind_0.begin(), ind_0.end());
  }
  range<iterator> equalRange_0(const t_tuple& t) const {
    return range<iterator>(ind_0.begin(), ind_0.end());
  }
  range<t_ind_0::iterator> equalRange_2(const t_tuple& t, context& h) const {
    t_tuple low(t);
    t_tuple high(t);
    low[0] = MIN_RAM_DOMAIN;
    high[0] = MAX_RAM_DOMAIN;
    return make_range(ind_0.lower_bound(low, h.hints_0),
                      ind_0.upper_bound(high, h.hints_0));
  }
  range<t_ind_0::iterator> equalRange_2(const t_tuple& t) const {
    context h;
    return equalRange_2(t, h);
  }
  range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
    auto pos = ind_0.find(t, h.hints_0);
    auto fin = ind_0.end();
    if (pos != fin) {
      fin = pos;
      ++fin;
    }
    return make_range(pos, fin);
  }
  range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
    context h;
    return equalRange_3(t, h);
  }
  bool empty() const { return ind_0.empty(); }
  std::vector<range<iterator>> partition() const {
    return ind_0.getChunks(400);
  }
  void purge() { ind_0.clear(); }
  iterator begin() const { return ind_0.begin(); }
  iterator end() const { return ind_0.end(); }
  void printHintStatistics(std::ostream& o, const std::string prefix) const {
    const auto& stats_0 = ind_0.getHintStatistics();
    o << prefix << "arity 2 direct b-tree index [1,0]: (hits/misses/total)\n";
    o << prefix << "Insert: " << stats_0.inserts.getHits() << "/"
      << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses()
      << "\n";
    o << prefix << "Contains: " << stats_0.contains.getHits() << "/"
      << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses()
      << "\n";
    o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/"
      << stats_0.lower_bound.getMisses() << "/"
      << stats_0.lower_bound.getAccesses() << "\n";
    o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/"
      << stats_0.upper_bound.getMisses() << "/"
      << stats_0.upper_bound.getAccesses() << "\n";
  }
};
struct t_btree_2__0_1__1__3 {
  using t_tuple = Tuple<RamDomain, 2>;
  using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0, 1>>;
  t_ind_0 ind_0;
  using iterator = t_ind_0::iterator;
  struct context {
    t_ind_0::operation_hints hints_0;
  };
  context createContext() { return context(); }
  bool insert(const t_tuple& t) {
    context h;
    return insert(t, h);
  }
  bool insert(const t_tuple& t, context& h) {
    if (ind_0.insert(t, h.hints_0)) {
      return true;
    } else
      return false;
  }
  bool insert(const RamDomain* ramDomain) {
    RamDomain data[2];
    std::copy(ramDomain, ramDomain + 2, data);
    const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
    context h;
    return insert(tuple, h);
  }
  bool insert(RamDomain a0, RamDomain a1) {
    RamDomain data[2] = {a0, a1};
    return insert(data);
  }
  template <typename T>
  void insertAll(T& other) {
    for (auto const& cur : other) {
      insert(cur);
    }
  }
  void insertAll(t_btree_2__0_1__1__3& other) { ind_0.insertAll(other.ind_0); }
  bool contains(const t_tuple& t, context& h) const {
    return ind_0.contains(t, h.hints_0);
  }
  bool contains(const t_tuple& t) const {
    context h;
    return contains(t, h);
  }
  std::size_t size() const { return ind_0.size(); }
  iterator find(const t_tuple& t, context& h) const {
    return ind_0.find(t, h.hints_0);
  }
  iterator find(const t_tuple& t) const {
    context h;
    return find(t, h);
  }
  range<iterator> equalRange_0(const t_tuple& t, context& h) const {
    return range<iterator>(ind_0.begin(), ind_0.end());
  }
  range<iterator> equalRange_0(const t_tuple& t) const {
    return range<iterator>(ind_0.begin(), ind_0.end());
  }
  range<t_ind_0::iterator> equalRange_1(const t_tuple& t, context& h) const {
    t_tuple low(t);
    t_tuple high(t);
    low[1] = MIN_RAM_DOMAIN;
    high[1] = MAX_RAM_DOMAIN;
    return make_range(ind_0.lower_bound(low, h.hints_0),
                      ind_0.upper_bound(high, h.hints_0));
  }
  range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
    context h;
    return equalRange_1(t, h);
  }
  range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
    auto pos = ind_0.find(t, h.hints_0);
    auto fin = ind_0.end();
    if (pos != fin) {
      fin = pos;
      ++fin;
    }
    return make_range(pos, fin);
  }
  range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
    context h;
    return equalRange_3(t, h);
  }
  bool empty() const { return ind_0.empty(); }
  std::vector<range<iterator>> partition() const {
    return ind_0.getChunks(400);
  }
  void purge() { ind_0.clear(); }
  iterator begin() const { return ind_0.begin(); }
  iterator end() const { return ind_0.end(); }
  void printHintStatistics(std::ostream& o, const std::string prefix) const {
    const auto& stats_0 = ind_0.getHintStatistics();
    o << prefix << "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
    o << prefix << "Insert: " << stats_0.inserts.getHits() << "/"
      << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses()
      << "\n";
    o << prefix << "Contains: " << stats_0.contains.getHits() << "/"
      << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses()
      << "\n";
    o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/"
      << stats_0.lower_bound.getMisses() << "/"
      << stats_0.lower_bound.getAccesses() << "\n";
    o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/"
      << stats_0.upper_bound.getMisses() << "/"
      << stats_0.upper_bound.getAccesses() << "\n";
  }
};
struct t_btree_1__0__1 {
  using t_tuple = Tuple<RamDomain, 1>;
  using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0>>;
  t_ind_0 ind_0;
  using iterator = t_ind_0::iterator;
  struct context {
    t_ind_0::operation_hints hints_0;
  };
  context createContext() { return context(); }
  bool insert(const t_tuple& t) {
    context h;
    return insert(t, h);
  }
  bool insert(const t_tuple& t, context& h) {
    if (ind_0.insert(t, h.hints_0)) {
      return true;
    } else
      return false;
  }
  bool insert(const RamDomain* ramDomain) {
    RamDomain data[1];
    std::copy(ramDomain, ramDomain + 1, data);
    const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
    context h;
    return insert(tuple, h);
  }
  bool insert(RamDomain a0) {
    RamDomain data[1] = {a0};
    return insert(data);
  }
  template <typename T>
  void insertAll(T& other) {
    for (auto const& cur : other) {
      insert(cur);
    }
  }
  void insertAll(t_btree_1__0__1& other) { ind_0.insertAll(other.ind_0); }
  bool contains(const t_tuple& t, context& h) const {
    return ind_0.contains(t, h.hints_0);
  }
  bool contains(const t_tuple& t) const {
    context h;
    return contains(t, h);
  }
  std::size_t size() const { return ind_0.size(); }
  iterator find(const t_tuple& t, context& h) const {
    return ind_0.find(t, h.hints_0);
  }
  iterator find(const t_tuple& t) const {
    context h;
    return find(t, h);
  }
  range<iterator> equalRange_0(const t_tuple& t, context& h) const {
    return range<iterator>(ind_0.begin(), ind_0.end());
  }
  range<iterator> equalRange_0(const t_tuple& t) const {
    return range<iterator>(ind_0.begin(), ind_0.end());
  }
  range<t_ind_0::iterator> equalRange_1(const t_tuple& t, context& h) const {
    auto pos = ind_0.find(t, h.hints_0);
    auto fin = ind_0.end();
    if (pos != fin) {
      fin = pos;
      ++fin;
    }
    return make_range(pos, fin);
  }
  range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
    context h;
    return equalRange_1(t, h);
  }
  bool empty() const { return ind_0.empty(); }
  std::vector<range<iterator>> partition() const {
    return ind_0.getChunks(400);
  }
  void purge() { ind_0.clear(); }
  iterator begin() const { return ind_0.begin(); }
  iterator end() const { return ind_0.end(); }
  void printHintStatistics(std::ostream& o, const std::string prefix) const {
    const auto& stats_0 = ind_0.getHintStatistics();
    o << prefix << "arity 1 direct b-tree index [0]: (hits/misses/total)\n";
    o << prefix << "Insert: " << stats_0.inserts.getHits() << "/"
      << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses()
      << "\n";
    o << prefix << "Contains: " << stats_0.contains.getHits() << "/"
      << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses()
      << "\n";
    o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/"
      << stats_0.lower_bound.getMisses() << "/"
      << stats_0.lower_bound.getAccesses() << "\n";
    o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/"
      << stats_0.upper_bound.getMisses() << "/"
      << stats_0.upper_bound.getAccesses() << "\n";
  }
};
struct t_btree_2__0_1__3 {
  using t_tuple = Tuple<RamDomain, 2>;
  using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0, 1>>;
  t_ind_0 ind_0;
  using iterator = t_ind_0::iterator;
  struct context {
    t_ind_0::operation_hints hints_0;
  };
  context createContext() { return context(); }
  bool insert(const t_tuple& t) {
    context h;
    return insert(t, h);
  }
  bool insert(const t_tuple& t, context& h) {
    if (ind_0.insert(t, h.hints_0)) {
      return true;
    } else
      return false;
  }
  bool insert(const RamDomain* ramDomain) {
    RamDomain data[2];
    std::copy(ramDomain, ramDomain + 2, data);
    const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
    context h;
    return insert(tuple, h);
  }
  bool insert(RamDomain a0, RamDomain a1) {
    RamDomain data[2] = {a0, a1};
    return insert(data);
  }
  template <typename T>
  void insertAll(T& other) {
    for (auto const& cur : other) {
      insert(cur);
    }
  }
  void insertAll(t_btree_2__0_1__3& other) { ind_0.insertAll(other.ind_0); }
  bool contains(const t_tuple& t, context& h) const {
    return ind_0.contains(t, h.hints_0);
  }
  bool contains(const t_tuple& t) const {
    context h;
    return contains(t, h);
  }
  std::size_t size() const { return ind_0.size(); }
  iterator find(const t_tuple& t, context& h) const {
    return ind_0.find(t, h.hints_0);
  }
  iterator find(const t_tuple& t) const {
    context h;
    return find(t, h);
  }
  range<iterator> equalRange_0(const t_tuple& t, context& h) const {
    return range<iterator>(ind_0.begin(), ind_0.end());
  }
  range<iterator> equalRange_0(const t_tuple& t) const {
    return range<iterator>(ind_0.begin(), ind_0.end());
  }
  range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
    auto pos = ind_0.find(t, h.hints_0);
    auto fin = ind_0.end();
    if (pos != fin) {
      fin = pos;
      ++fin;
    }
    return make_range(pos, fin);
  }
  range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
    context h;
    return equalRange_3(t, h);
  }
  bool empty() const { return ind_0.empty(); }
  std::vector<range<iterator>> partition() const {
    return ind_0.getChunks(400);
  }
  void purge() { ind_0.clear(); }
  iterator begin() const { return ind_0.begin(); }
  iterator end() const { return ind_0.end(); }
  void printHintStatistics(std::ostream& o, const std::string prefix) const {
    const auto& stats_0 = ind_0.getHintStatistics();
    o << prefix << "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
    o << prefix << "Insert: " << stats_0.inserts.getHits() << "/"
      << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses()
      << "\n";
    o << prefix << "Contains: " << stats_0.contains.getHits() << "/"
      << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses()
      << "\n";
    o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/"
      << stats_0.lower_bound.getMisses() << "/"
      << stats_0.lower_bound.getAccesses() << "\n";
    o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/"
      << stats_0.upper_bound.getMisses() << "/"
      << stats_0.upper_bound.getAccesses() << "\n";
  }
};

class Sf_topological_order : public SouffleProgram {
 private:
  static inline bool regex_wrapper(const std::string& pattern,
                                   const std::string& text) {
    bool result = false;
    try {
      result = std::regex_match(text, std::regex(pattern));
    } catch (...) {
      std::cerr << "warning: wrong pattern provided for match(\"" << pattern
                << "\",\"" << text << "\").\n";
    }
    return result;
  }

 private:
  static inline std::string substr_wrapper(const std::string& str, size_t idx,
                                           size_t len) {
    std::string result;
    try {
      result = str.substr(idx, len);
    } catch (...) {
      std::cerr << "warning: wrong index position provided by substr(\"";
      std::cerr << str << "\"," << (int32_t)idx << "," << (int32_t)len
                << ") functor.\n";
    }
    return result;
  }

 private:
  static inline RamDomain wrapper_tonumber(const std::string& str) {
    RamDomain result = 0;
    try {
      result = stord(str);
    } catch (...) {
      std::cerr << "error: wrong string provided by to_number(\"";
      std::cerr << str << "\") functor.\n";
      raise(SIGFPE);
    }
    return result;
  }

 public:
  // -- initialize symbol table --
  SymbolTable symTable;  // -- Table: edge
  std::unique_ptr<t_btree_2__1_0__0_1__1__2__3> rel_1_edge =
      std::make_unique<t_btree_2__1_0__0_1__1__2__3>();
  souffle::RelationWrapper<0, t_btree_2__1_0__0_1__1__2__3, Tuple<RamDomain, 2>,
                           2, 1>
      wrapper_rel_1_edge;
  // -- Table: is_after
  std::unique_ptr<t_btree_2__1_0__2__3> rel_2_is_after =
      std::make_unique<t_btree_2__1_0__2__3>();
  souffle::RelationWrapper<1, t_btree_2__1_0__2__3, Tuple<RamDomain, 2>, 2, 1>
      wrapper_rel_2_is_after;
  // -- Table: @delta_is_after
  std::unique_ptr<t_btree_2__1_0__2__3> rel_3_delta_is_after =
      std::make_unique<t_btree_2__1_0__2__3>();
  // -- Table: @new_is_after
  std::unique_ptr<t_btree_2__1_0__2__3> rel_4_new_is_after =
      std::make_unique<t_btree_2__1_0__2__3>();
  // -- Table: is_before
  std::unique_ptr<t_btree_2__0_1__1__3> rel_5_is_before =
      std::make_unique<t_btree_2__0_1__1__3>();
  souffle::RelationWrapper<2, t_btree_2__0_1__1__3, Tuple<RamDomain, 2>, 2, 1>
      wrapper_rel_5_is_before;
  // -- Table: @delta_is_before
  std::unique_ptr<t_btree_2__0_1__1__3> rel_6_delta_is_before =
      std::make_unique<t_btree_2__0_1__1__3>();
  // -- Table: @new_is_before
  std::unique_ptr<t_btree_2__0_1__1__3> rel_7_new_is_before =
      std::make_unique<t_btree_2__0_1__1__3>();
  // -- Table: vertex
  std::unique_ptr<t_btree_1__0__1> rel_8_vertex =
      std::make_unique<t_btree_1__0__1>();
  souffle::RelationWrapper<3, t_btree_1__0__1, Tuple<RamDomain, 1>, 1, 1>
      wrapper_rel_8_vertex;
  // -- Table: indices
  std::unique_ptr<t_btree_2__0_1__3> rel_9_indices =
      std::make_unique<t_btree_2__0_1__3>();
  souffle::RelationWrapper<4, t_btree_2__0_1__3, Tuple<RamDomain, 2>, 2, 1>
      wrapper_rel_9_indices;
  // -- Table: @delta_indices
  std::unique_ptr<t_btree_2__0_1__1__3> rel_10_delta_indices =
      std::make_unique<t_btree_2__0_1__1__3>();
  // -- Table: @new_indices
  std::unique_ptr<t_btree_2__0_1__1__3> rel_11_new_indices =
      std::make_unique<t_btree_2__0_1__1__3>();
  // -- Table: index
  std::unique_ptr<t_btree_2__0_1__3> rel_12_index =
      std::make_unique<t_btree_2__0_1__3>();
  souffle::RelationWrapper<5, t_btree_2__0_1__3, Tuple<RamDomain, 2>, 2, 1>
      wrapper_rel_12_index;

 public:
  Sf_topological_order()
      : wrapper_rel_1_edge(*rel_1_edge, symTable, "edge",
                           std::array<const char*, 2>{{"i:number", "i:number"}},
                           std::array<const char*, 2>{{"v1", "v2"}}),

        wrapper_rel_2_is_after(
            *rel_2_is_after, symTable, "is_after",
            std::array<const char*, 2>{{"i:number", "i:number"}},
            std::array<const char*, 2>{{"v1", "v2"}}),

        wrapper_rel_5_is_before(
            *rel_5_is_before, symTable, "is_before",
            std::array<const char*, 2>{{"i:number", "i:number"}},
            std::array<const char*, 2>{{"v1", "v2"}}),

        wrapper_rel_8_vertex(*rel_8_vertex, symTable, "vertex",
                             std::array<const char*, 1>{{"i:number"}},
                             std::array<const char*, 1>{{"v"}}),

        wrapper_rel_9_indices(
            *rel_9_indices, symTable, "indices",
            std::array<const char*, 2>{{"i:number", "i:number"}},
            std::array<const char*, 2>{{"v", "i"}}),

        wrapper_rel_12_index(
            *rel_12_index, symTable, "index",
            std::array<const char*, 2>{{"i:number", "i:number"}},
            std::array<const char*, 2>{{"v", "i"}}) {
    addRelation("edge", &wrapper_rel_1_edge, true, false);
    addRelation("is_after", &wrapper_rel_2_is_after, false, true);
    addRelation("is_before", &wrapper_rel_5_is_before, false, true);
    addRelation("vertex", &wrapper_rel_8_vertex, false, false);
    addRelation("indices", &wrapper_rel_9_indices, false, true);
    addRelation("index", &wrapper_rel_12_index, false, true);
  }
  ~Sf_topological_order() {}

 private:
  void runFunction(std::string inputDirectory = ".",
                   std::string outputDirectory = ".",
                   size_t stratumIndex = (size_t)-1, bool performIO = false) {
    SignalHandler::instance()->set();
    std::atomic<size_t> iter(0);

#if defined(_OPENMP)
    if (getNumThreads() > 0) {
      omp_set_num_threads(getNumThreads());
    }
#endif

    // -- query evaluation --
    /* BEGIN STRATUM 0 */
    [&]() {
      if (performIO) {
        try {
          std::map<std::string, std::string> directiveMap(
              {{"IO", "file"}, {"filename", "./edge.facts"}, {"name", "edge"}});
          if (!inputDirectory.empty() && directiveMap["IO"] == "file" &&
              directiveMap["filename"].front() != '/') {
            directiveMap["filename"] =
                inputDirectory + "/" + directiveMap["filename"];
          }
          IODirectives ioDirectives(directiveMap);
          IOSystem::getInstance()
              .getReader(std::vector<bool>({0, 0}), symTable, ioDirectives,
                         false, 1)
              ->readAll(*rel_1_edge);
        } catch (std::exception& e) {
          std::cerr << "Error loading data: " << e.what() << '\n';
        }
      }
    }();
    /* END STRATUM 0 */
    /* BEGIN STRATUM 1 */
    [&]() {
      SignalHandler::instance()->setMsg(R"_(is_after(x,y) :- 
   edge(y,x).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [43:1-44:16])_");
      if (!(rel_1_edge->empty())) {
        [&]() {
          CREATE_OP_CONTEXT(rel_1_edge_op_ctxt, rel_1_edge->createContext());
          CREATE_OP_CONTEXT(rel_2_is_after_op_ctxt,
                            rel_2_is_after->createContext());
          for (const auto& env0 : *rel_1_edge) {
            Tuple<RamDomain, 2> tuple{{static_cast<RamDomain>(env0[1]),
                                       static_cast<RamDomain>(env0[0])}};
            rel_2_is_after->insert(tuple,
                                   READ_OP_CONTEXT(rel_2_is_after_op_ctxt));
          }
        }();
      }
      rel_3_delta_is_after->insertAll(*rel_2_is_after);
      iter = 0;
      for (;;) {
        SignalHandler::instance()->setMsg(R"_(is_after(x,y) :- 
   is_after(z,x),
   is_after(y,z).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [47:1-49:20])_");
        if (!(rel_2_is_after->empty()) && !(rel_3_delta_is_after->empty())) {
          [&]() {
            CREATE_OP_CONTEXT(rel_2_is_after_op_ctxt,
                              rel_2_is_after->createContext());
            CREATE_OP_CONTEXT(rel_3_delta_is_after_op_ctxt,
                              rel_3_delta_is_after->createContext());
            CREATE_OP_CONTEXT(rel_4_new_is_after_op_ctxt,
                              rel_4_new_is_after->createContext());
            for (const auto& env0 : *rel_3_delta_is_after) {
              const Tuple<RamDomain, 2> key{{0, env0[0]}};
              auto range = rel_2_is_after->equalRange_2(
                  key, READ_OP_CONTEXT(rel_2_is_after_op_ctxt));
              for (const auto& env1 : range) {
                if (!(rel_2_is_after->contains(
                        Tuple<RamDomain, 2>{{env0[1], env1[0]}},
                        READ_OP_CONTEXT(rel_2_is_after_op_ctxt))) &&
                    !(rel_3_delta_is_after->contains(
                        Tuple<RamDomain, 2>{{env1[0], env0[0]}},
                        READ_OP_CONTEXT(rel_3_delta_is_after_op_ctxt)))) {
                  Tuple<RamDomain, 2> tuple{{static_cast<RamDomain>(env0[1]),
                                             static_cast<RamDomain>(env1[0])}};
                  rel_4_new_is_after->insert(
                      tuple, READ_OP_CONTEXT(rel_4_new_is_after_op_ctxt));
                }
              }
            }
          }();
        }
        SignalHandler::instance()->setMsg(R"_(is_after(x,y) :- 
   is_after(z,x),
   is_after(y,z).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [47:1-49:20])_");
        if (!(rel_3_delta_is_after->empty()) && !(rel_2_is_after->empty())) {
          [&]() {
            CREATE_OP_CONTEXT(rel_2_is_after_op_ctxt,
                              rel_2_is_after->createContext());
            CREATE_OP_CONTEXT(rel_3_delta_is_after_op_ctxt,
                              rel_3_delta_is_after->createContext());
            CREATE_OP_CONTEXT(rel_4_new_is_after_op_ctxt,
                              rel_4_new_is_after->createContext());
            for (const auto& env0 : *rel_2_is_after) {
              const Tuple<RamDomain, 2> key{{0, env0[0]}};
              auto range = rel_3_delta_is_after->equalRange_2(
                  key, READ_OP_CONTEXT(rel_3_delta_is_after_op_ctxt));
              for (const auto& env1 : range) {
                if (!(rel_2_is_after->contains(
                        Tuple<RamDomain, 2>{{env0[1], env1[0]}},
                        READ_OP_CONTEXT(rel_2_is_after_op_ctxt)))) {
                  Tuple<RamDomain, 2> tuple{{static_cast<RamDomain>(env0[1]),
                                             static_cast<RamDomain>(env1[0])}};
                  rel_4_new_is_after->insert(
                      tuple, READ_OP_CONTEXT(rel_4_new_is_after_op_ctxt));
                }
              }
            }
          }();
        }
        if (rel_4_new_is_after->empty()) break;
        rel_2_is_after->insertAll(*rel_4_new_is_after);
        std::swap(rel_3_delta_is_after, rel_4_new_is_after);
        rel_4_new_is_after->purge();
        iter++;
      }
      iter = 0;
      if (!isHintsProfilingEnabled()) rel_3_delta_is_after->purge();
      if (!isHintsProfilingEnabled()) rel_4_new_is_after->purge();
      if (performIO) {
        try {
          std::map<std::string, std::string> directiveMap(
              {{"IO", "file"},
               {"attributeNames", "v1\tv2"},
               {"filename", "./is_after.ans"},
               {"name", "is_after"}});
          if (!outputDirectory.empty() && directiveMap["IO"] == "file" &&
              directiveMap["filename"].front() != '/') {
            directiveMap["filename"] =
                outputDirectory + "/" + directiveMap["filename"];
          }
          IODirectives ioDirectives(directiveMap);
          IOSystem::getInstance()
              .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives,
                         false, 1)
              ->writeAll(*rel_2_is_after);
        } catch (std::exception& e) {
          std::cerr << e.what();
          exit(1);
        }
      }
    }();
    /* END STRATUM 1 */
    /* BEGIN STRATUM 2 */
    [&]() {
      SignalHandler::instance()->setMsg(R"_(is_before(x,y) :- 
   edge(x,y).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [34:1-35:16])_");
      if (!(rel_1_edge->empty())) {
        [&]() {
          CREATE_OP_CONTEXT(rel_1_edge_op_ctxt, rel_1_edge->createContext());
          CREATE_OP_CONTEXT(rel_5_is_before_op_ctxt,
                            rel_5_is_before->createContext());
          for (const auto& env0 : *rel_1_edge) {
            Tuple<RamDomain, 2> tuple{{static_cast<RamDomain>(env0[0]),
                                       static_cast<RamDomain>(env0[1])}};
            rel_5_is_before->insert(tuple,
                                    READ_OP_CONTEXT(rel_5_is_before_op_ctxt));
          }
        }();
      }
      rel_6_delta_is_before->insertAll(*rel_5_is_before);
      iter = 0;
      for (;;) {
        SignalHandler::instance()->setMsg(R"_(is_before(x,y) :- 
   is_before(x,z),
   is_before(z,y).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [38:1-40:21])_");
        if (!(rel_5_is_before->empty()) && !(rel_6_delta_is_before->empty())) {
          [&]() {
            CREATE_OP_CONTEXT(rel_7_new_is_before_op_ctxt,
                              rel_7_new_is_before->createContext());
            CREATE_OP_CONTEXT(rel_6_delta_is_before_op_ctxt,
                              rel_6_delta_is_before->createContext());
            CREATE_OP_CONTEXT(rel_5_is_before_op_ctxt,
                              rel_5_is_before->createContext());
            for (const auto& env0 : *rel_6_delta_is_before) {
              const Tuple<RamDomain, 2> key{{env0[1], 0}};
              auto range = rel_5_is_before->equalRange_1(
                  key, READ_OP_CONTEXT(rel_5_is_before_op_ctxt));
              for (const auto& env1 : range) {
                if (!(rel_5_is_before->contains(
                        Tuple<RamDomain, 2>{{env0[0], env1[1]}},
                        READ_OP_CONTEXT(rel_5_is_before_op_ctxt))) &&
                    !(rel_6_delta_is_before->contains(
                        Tuple<RamDomain, 2>{{env0[1], env1[1]}},
                        READ_OP_CONTEXT(rel_6_delta_is_before_op_ctxt)))) {
                  Tuple<RamDomain, 2> tuple{{static_cast<RamDomain>(env0[0]),
                                             static_cast<RamDomain>(env1[1])}};
                  rel_7_new_is_before->insert(
                      tuple, READ_OP_CONTEXT(rel_7_new_is_before_op_ctxt));
                }
              }
            }
          }();
        }
        SignalHandler::instance()->setMsg(R"_(is_before(x,y) :- 
   is_before(x,z),
   is_before(z,y).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [38:1-40:21])_");
        if (!(rel_6_delta_is_before->empty()) && !(rel_5_is_before->empty())) {
          [&]() {
            CREATE_OP_CONTEXT(rel_7_new_is_before_op_ctxt,
                              rel_7_new_is_before->createContext());
            CREATE_OP_CONTEXT(rel_6_delta_is_before_op_ctxt,
                              rel_6_delta_is_before->createContext());
            CREATE_OP_CONTEXT(rel_5_is_before_op_ctxt,
                              rel_5_is_before->createContext());
            for (const auto& env0 : *rel_5_is_before) {
              const Tuple<RamDomain, 2> key{{env0[1], 0}};
              auto range = rel_6_delta_is_before->equalRange_1(
                  key, READ_OP_CONTEXT(rel_6_delta_is_before_op_ctxt));
              for (const auto& env1 : range) {
                if (!(rel_5_is_before->contains(
                        Tuple<RamDomain, 2>{{env0[0], env1[1]}},
                        READ_OP_CONTEXT(rel_5_is_before_op_ctxt)))) {
                  Tuple<RamDomain, 2> tuple{{static_cast<RamDomain>(env0[0]),
                                             static_cast<RamDomain>(env1[1])}};
                  rel_7_new_is_before->insert(
                      tuple, READ_OP_CONTEXT(rel_7_new_is_before_op_ctxt));
                }
              }
            }
          }();
        }
        if (rel_7_new_is_before->empty()) break;
        rel_5_is_before->insertAll(*rel_7_new_is_before);
        std::swap(rel_6_delta_is_before, rel_7_new_is_before);
        rel_7_new_is_before->purge();
        iter++;
      }
      iter = 0;
      if (!isHintsProfilingEnabled()) rel_6_delta_is_before->purge();
      if (!isHintsProfilingEnabled()) rel_7_new_is_before->purge();
      if (performIO) {
        try {
          std::map<std::string, std::string> directiveMap(
              {{"IO", "file"},
               {"attributeNames", "v1\tv2"},
               {"filename", "./is_before.ans"},
               {"name", "is_before"}});
          if (!outputDirectory.empty() && directiveMap["IO"] == "file" &&
              directiveMap["filename"].front() != '/') {
            directiveMap["filename"] =
                outputDirectory + "/" + directiveMap["filename"];
          }
          IODirectives ioDirectives(directiveMap);
          IOSystem::getInstance()
              .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives,
                         false, 1)
              ->writeAll(*rel_5_is_before);
        } catch (std::exception& e) {
          std::cerr << e.what();
          exit(1);
        }
      }
    }();
    /* END STRATUM 2 */
    /* BEGIN STRATUM 3 */
    [&]() {
      SignalHandler::instance()->setMsg(R"_(vertex(v) :- 
   edge(v,_).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [13:1-13:24])_");
      if (!(rel_1_edge->empty())) {
        [&]() {
          CREATE_OP_CONTEXT(rel_1_edge_op_ctxt, rel_1_edge->createContext());
          CREATE_OP_CONTEXT(rel_8_vertex_op_ctxt,
                            rel_8_vertex->createContext());
          for (const auto& env0 : *rel_1_edge) {
            Tuple<RamDomain, 1> tuple{{static_cast<RamDomain>(env0[0])}};
            rel_8_vertex->insert(tuple, READ_OP_CONTEXT(rel_8_vertex_op_ctxt));
          }
        }();
      }
      SignalHandler::instance()->setMsg(R"_(vertex(v) :- 
   edge(_,v).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [14:1-14:24])_");
      if (!(rel_1_edge->empty())) {
        [&]() {
          CREATE_OP_CONTEXT(rel_1_edge_op_ctxt, rel_1_edge->createContext());
          CREATE_OP_CONTEXT(rel_8_vertex_op_ctxt,
                            rel_8_vertex->createContext());
          for (const auto& env0 : *rel_1_edge) {
            Tuple<RamDomain, 1> tuple{{static_cast<RamDomain>(env0[1])}};
            rel_8_vertex->insert(tuple, READ_OP_CONTEXT(rel_8_vertex_op_ctxt));
          }
        }();
      }
    }();
    /* END STRATUM 3 */
    /* BEGIN STRATUM 4 */
    [&]() {
      SignalHandler::instance()->setMsg(R"_(indices(x,0) :- 
   vertex(x),
   !edge(_,x),
   !edge(x,_).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [52:1-55:17])_");
      if (!(rel_8_vertex->empty())) {
        [&]() {
          CREATE_OP_CONTEXT(rel_1_edge_op_ctxt, rel_1_edge->createContext());
          CREATE_OP_CONTEXT(rel_9_indices_op_ctxt,
                            rel_9_indices->createContext());
          CREATE_OP_CONTEXT(rel_8_vertex_op_ctxt,
                            rel_8_vertex->createContext());
          for (const auto& env0 : *rel_8_vertex) {
            if (!(!rel_1_edge
                       ->equalRange_1(Tuple<RamDomain, 2>{{env0[0], 0}},
                                      READ_OP_CONTEXT(rel_1_edge_op_ctxt))
                       .empty()) &&
                !(!rel_1_edge
                       ->equalRange_2(Tuple<RamDomain, 2>{{0, env0[0]}},
                                      READ_OP_CONTEXT(rel_1_edge_op_ctxt))
                       .empty())) {
              Tuple<RamDomain, 2> tuple{{static_cast<RamDomain>(env0[0]),
                                         static_cast<RamDomain>(RamDomain(0))}};
              rel_9_indices->insert(tuple,
                                    READ_OP_CONTEXT(rel_9_indices_op_ctxt));
            }
          }
        }();
      }
      SignalHandler::instance()->setMsg(R"_(indices(x,1) :- 
   vertex(x),
   edge(x,_),
   !edge(_,x).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [58:1-61:16])_");
      if (!(rel_1_edge->empty()) && !(rel_8_vertex->empty())) {
        [&]() {
          CREATE_OP_CONTEXT(rel_1_edge_op_ctxt, rel_1_edge->createContext());
          CREATE_OP_CONTEXT(rel_9_indices_op_ctxt,
                            rel_9_indices->createContext());
          CREATE_OP_CONTEXT(rel_8_vertex_op_ctxt,
                            rel_8_vertex->createContext());
          for (const auto& env0 : *rel_8_vertex) {
            if (!(!rel_1_edge
                       ->equalRange_2(Tuple<RamDomain, 2>{{0, env0[0]}},
                                      READ_OP_CONTEXT(rel_1_edge_op_ctxt))
                       .empty()) &&
                !rel_1_edge
                     ->equalRange_1(Tuple<RamDomain, 2>{{env0[0], 0}},
                                    READ_OP_CONTEXT(rel_1_edge_op_ctxt))
                     .empty()) {
              Tuple<RamDomain, 2> tuple{{static_cast<RamDomain>(env0[0]),
                                         static_cast<RamDomain>(RamDomain(1))}};
              rel_9_indices->insert(tuple,
                                    READ_OP_CONTEXT(rel_9_indices_op_ctxt));
            }
          }
        }();
      }
      rel_10_delta_indices->insertAll(*rel_9_indices);
      iter = 0;
      for (;;) {
        SignalHandler::instance()->setMsg(R"_(indices(x,(i+1)) :- 
   is_before(y,x),
   is_after(x,y),
   indices(y,i),
   !is_before(x,y).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [64:1-68:19])_");
        if (!(rel_10_delta_indices->empty()) && !(rel_2_is_after->empty()) &&
            !(rel_5_is_before->empty())) {
          [&]() {
            CREATE_OP_CONTEXT(rel_2_is_after_op_ctxt,
                              rel_2_is_after->createContext());
            CREATE_OP_CONTEXT(rel_9_indices_op_ctxt,
                              rel_9_indices->createContext());
            CREATE_OP_CONTEXT(rel_5_is_before_op_ctxt,
                              rel_5_is_before->createContext());
            CREATE_OP_CONTEXT(rel_10_delta_indices_op_ctxt,
                              rel_10_delta_indices->createContext());
            CREATE_OP_CONTEXT(rel_11_new_indices_op_ctxt,
                              rel_11_new_indices->createContext());
            for (const auto& env0 : *rel_5_is_before) {
              if (!(rel_5_is_before->contains(
                      Tuple<RamDomain, 2>{{env0[1], env0[0]}},
                      READ_OP_CONTEXT(rel_5_is_before_op_ctxt))) &&
                  rel_2_is_after->contains(
                      Tuple<RamDomain, 2>{{env0[1], env0[0]}},
                      READ_OP_CONTEXT(rel_2_is_after_op_ctxt))) {
                const Tuple<RamDomain, 2> key{{env0[0], 0}};
                auto range = rel_10_delta_indices->equalRange_1(
                    key, READ_OP_CONTEXT(rel_10_delta_indices_op_ctxt));
                for (const auto& env1 : range) {
                  if (!(rel_9_indices->contains(
                          Tuple<RamDomain, 2>{
                              {env0[1], (env1[1]) + (RamDomain(1))}},
                          READ_OP_CONTEXT(rel_9_indices_op_ctxt)))) {
                    Tuple<RamDomain, 2> tuple{
                        {static_cast<RamDomain>(env0[1]),
                         static_cast<RamDomain>((env1[1]) + (RamDomain(1)))}};
                    rel_11_new_indices->insert(
                        tuple, READ_OP_CONTEXT(rel_11_new_indices_op_ctxt));
                  }
                }
              }
            }
          }();
        }
        if (rel_11_new_indices->empty()) break;
        rel_9_indices->insertAll(*rel_11_new_indices);
        std::swap(rel_10_delta_indices, rel_11_new_indices);
        rel_11_new_indices->purge();
        iter++;
      }
      iter = 0;
      if (!isHintsProfilingEnabled()) rel_10_delta_indices->purge();
      if (!isHintsProfilingEnabled()) rel_11_new_indices->purge();
      if (performIO) {
        try {
          std::map<std::string, std::string> directiveMap(
              {{"IO", "file"},
               {"attributeNames", "v\ti"},
               {"filename", "./indices.ans"},
               {"name", "indices"}});
          if (!outputDirectory.empty() && directiveMap["IO"] == "file" &&
              directiveMap["filename"].front() != '/') {
            directiveMap["filename"] =
                outputDirectory + "/" + directiveMap["filename"];
          }
          IODirectives ioDirectives(directiveMap);
          IOSystem::getInstance()
              .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives,
                         false, 1)
              ->writeAll(*rel_9_indices);
        } catch (std::exception& e) {
          std::cerr << e.what();
          exit(1);
        }
      }
      if (!isHintsProfilingEnabled() && performIO) rel_1_edge->purge();
      if (!isHintsProfilingEnabled() && performIO) rel_8_vertex->purge();
      if (!isHintsProfilingEnabled() && performIO) rel_5_is_before->purge();
      if (!isHintsProfilingEnabled() && performIO) rel_2_is_after->purge();
    }();
    /* END STRATUM 4 */
    /* BEGIN STRATUM 5 */
    [&]() {
      SignalHandler::instance()->setMsg(R"_(index(x,i) :- 
   indices(x,i),
   !indices(x,(i+1)).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/topological_order/topological_order.dl [71:1-73:22])_");
      if (!(rel_9_indices->empty())) {
        [&]() {
          CREATE_OP_CONTEXT(rel_9_indices_op_ctxt,
                            rel_9_indices->createContext());
          CREATE_OP_CONTEXT(rel_12_index_op_ctxt,
                            rel_12_index->createContext());
          for (const auto& env0 : *rel_9_indices) {
            if (!(rel_9_indices->contains(
                    Tuple<RamDomain, 2>{{env0[0], (env0[1]) + (RamDomain(1))}},
                    READ_OP_CONTEXT(rel_9_indices_op_ctxt)))) {
              Tuple<RamDomain, 2> tuple{{static_cast<RamDomain>(env0[0]),
                                         static_cast<RamDomain>(env0[1])}};
              rel_12_index->insert(tuple,
                                   READ_OP_CONTEXT(rel_12_index_op_ctxt));
            }
          }
        }();
      }
      if (performIO) {
        try {
          std::map<std::string, std::string> directiveMap(
              {{"IO", "file"},
               {"attributeNames", "v\ti"},
               {"filename", "./index.ans"},
               {"name", "index"}});
          if (!outputDirectory.empty() && directiveMap["IO"] == "file" &&
              directiveMap["filename"].front() != '/') {
            directiveMap["filename"] =
                outputDirectory + "/" + directiveMap["filename"];
          }
          IODirectives ioDirectives(directiveMap);
          IOSystem::getInstance()
              .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives,
                         false, 1)
              ->writeAll(*rel_12_index);
        } catch (std::exception& e) {
          std::cerr << e.what();
          exit(1);
        }
      }
      if (!isHintsProfilingEnabled() && performIO) rel_9_indices->purge();
    }();
    /* END STRATUM 5 */

    // -- relation hint statistics --
    if (isHintsProfilingEnabled()) {
      std::cout << " -- Operation Hint Statistics --\n";
      std::cout << "Relation rel_1_edge:\n";
      rel_1_edge->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
      std::cout << "Relation rel_2_is_after:\n";
      rel_2_is_after->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
      std::cout << "Relation rel_3_delta_is_after:\n";
      rel_3_delta_is_after->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
      std::cout << "Relation rel_4_new_is_after:\n";
      rel_4_new_is_after->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
      std::cout << "Relation rel_5_is_before:\n";
      rel_5_is_before->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
      std::cout << "Relation rel_6_delta_is_before:\n";
      rel_6_delta_is_before->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
      std::cout << "Relation rel_7_new_is_before:\n";
      rel_7_new_is_before->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
      std::cout << "Relation rel_8_vertex:\n";
      rel_8_vertex->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
      std::cout << "Relation rel_9_indices:\n";
      rel_9_indices->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
      std::cout << "Relation rel_10_delta_indices:\n";
      rel_10_delta_indices->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
      std::cout << "Relation rel_11_new_indices:\n";
      rel_11_new_indices->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
      std::cout << "Relation rel_12_index:\n";
      rel_12_index->printHintStatistics(std::cout, "  ");
      std::cout << "\n";
    }
    SignalHandler::instance()->reset();
  }

 public:
  void run(size_t stratumIndex = (size_t)-1) override {
    runFunction(".", ".", stratumIndex, false);
  }

 public:
  void runAll(std::string inputDirectory = ".",
              std::string outputDirectory = ".",
              size_t stratumIndex = (size_t)-1) override {
    runFunction(inputDirectory, outputDirectory, stratumIndex, true);
  }

 public:
  void printAll(std::string outputDirectory = ".") override {
    try {
      std::map<std::string, std::string> directiveMap(
          {{"IO", "file"},
           {"attributeNames", "v1\tv2"},
           {"filename", "./is_after.ans"},
           {"name", "is_after"}});
      if (!outputDirectory.empty() && directiveMap["IO"] == "file" &&
          directiveMap["filename"].front() != '/') {
        directiveMap["filename"] =
            outputDirectory + "/" + directiveMap["filename"];
      }
      IODirectives ioDirectives(directiveMap);
      IOSystem::getInstance()
          .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives, false,
                     1)
          ->writeAll(*rel_2_is_after);
    } catch (std::exception& e) {
      std::cerr << e.what();
      exit(1);
    }
    try {
      std::map<std::string, std::string> directiveMap(
          {{"IO", "file"},
           {"attributeNames", "v1\tv2"},
           {"filename", "./is_before.ans"},
           {"name", "is_before"}});
      if (!outputDirectory.empty() && directiveMap["IO"] == "file" &&
          directiveMap["filename"].front() != '/') {
        directiveMap["filename"] =
            outputDirectory + "/" + directiveMap["filename"];
      }
      IODirectives ioDirectives(directiveMap);
      IOSystem::getInstance()
          .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives, false,
                     1)
          ->writeAll(*rel_5_is_before);
    } catch (std::exception& e) {
      std::cerr << e.what();
      exit(1);
    }
    try {
      std::map<std::string, std::string> directiveMap(
          {{"IO", "file"},
           {"attributeNames", "v\ti"},
           {"filename", "./indices.ans"},
           {"name", "indices"}});
      if (!outputDirectory.empty() && directiveMap["IO"] == "file" &&
          directiveMap["filename"].front() != '/') {
        directiveMap["filename"] =
            outputDirectory + "/" + directiveMap["filename"];
      }
      IODirectives ioDirectives(directiveMap);
      IOSystem::getInstance()
          .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives, false,
                     1)
          ->writeAll(*rel_9_indices);
    } catch (std::exception& e) {
      std::cerr << e.what();
      exit(1);
    }
    try {
      std::map<std::string, std::string> directiveMap(
          {{"IO", "file"},
           {"attributeNames", "v\ti"},
           {"filename", "./index.ans"},
           {"name", "index"}});
      if (!outputDirectory.empty() && directiveMap["IO"] == "file" &&
          directiveMap["filename"].front() != '/') {
        directiveMap["filename"] =
            outputDirectory + "/" + directiveMap["filename"];
      }
      IODirectives ioDirectives(directiveMap);
      IOSystem::getInstance()
          .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives, false,
                     1)
          ->writeAll(*rel_12_index);
    } catch (std::exception& e) {
      std::cerr << e.what();
      exit(1);
    }
  }

 public:
  void loadAll(std::string inputDirectory = ".") override {
    try {
      std::map<std::string, std::string> directiveMap(
          {{"IO", "file"}, {"filename", "./edge.facts"}, {"name", "edge"}});
      if (!inputDirectory.empty() && directiveMap["IO"] == "file" &&
          directiveMap["filename"].front() != '/') {
        directiveMap["filename"] =
            inputDirectory + "/" + directiveMap["filename"];
      }
      IODirectives ioDirectives(directiveMap);
      IOSystem::getInstance()
          .getReader(std::vector<bool>({0, 0}), symTable, ioDirectives, false,
                     1)
          ->readAll(*rel_1_edge);
    } catch (std::exception& e) {
      std::cerr << "Error loading data: " << e.what() << '\n';
    }
  }

 public:
  void dumpInputs(std::ostream& out = std::cout) override {
    try {
      IODirectives ioDirectives;
      ioDirectives.setIOType("stdout");
      ioDirectives.setRelationName("rel_1_edge");
      IOSystem::getInstance()
          .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives, false,
                     1)
          ->writeAll(*rel_1_edge);
    } catch (std::exception& e) {
      std::cerr << e.what();
      exit(1);
    }
  }

 public:
  void dumpOutputs(std::ostream& out = std::cout) override {
    try {
      IODirectives ioDirectives;
      ioDirectives.setIOType("stdout");
      ioDirectives.setRelationName("rel_2_is_after");
      IOSystem::getInstance()
          .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives, false,
                     1)
          ->writeAll(*rel_2_is_after);
    } catch (std::exception& e) {
      std::cerr << e.what();
      exit(1);
    }
    try {
      IODirectives ioDirectives;
      ioDirectives.setIOType("stdout");
      ioDirectives.setRelationName("rel_5_is_before");
      IOSystem::getInstance()
          .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives, false,
                     1)
          ->writeAll(*rel_5_is_before);
    } catch (std::exception& e) {
      std::cerr << e.what();
      exit(1);
    }
    try {
      IODirectives ioDirectives;
      ioDirectives.setIOType("stdout");
      ioDirectives.setRelationName("rel_9_indices");
      IOSystem::getInstance()
          .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives, false,
                     1)
          ->writeAll(*rel_9_indices);
    } catch (std::exception& e) {
      std::cerr << e.what();
      exit(1);
    }
    try {
      IODirectives ioDirectives;
      ioDirectives.setIOType("stdout");
      ioDirectives.setRelationName("rel_12_index");
      IOSystem::getInstance()
          .getWriter(std::vector<bool>({0, 0}), symTable, ioDirectives, false,
                     1)
          ->writeAll(*rel_12_index);
    } catch (std::exception& e) {
      std::cerr << e.what();
      exit(1);
    }
  }

 public:
  SymbolTable& getSymbolTable() override { return symTable; }
};
SouffleProgram* newInstance_topological_order() {
  return new Sf_topological_order;
}
SymbolTable* getST_topological_order(SouffleProgram* p) {
  return &reinterpret_cast<Sf_topological_order*>(p)->symTable;
}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_topological_order : public souffle::ProgramFactory {
  SouffleProgram* newInstance() { return new Sf_topological_order(); };

 public:
  factory_Sf_topological_order() : ProgramFactory("topological_order") {}
};
static factory_Sf_topological_order __factory_Sf_topological_order_instance;
}
#else
}
int main(int argc, char** argv) {
  try {
    souffle::CmdOptions opt(R"(topological_order.dl)",
                            R"(.)",
                            R"(.)", false,
                            R"()", 1, -1);
    if (!opt.parse(argc, argv)) return 1;
    souffle::Sf_topological_order obj;
#if defined(_OPENMP)
    obj.setNumThreads(opt.getNumJobs());

#endif
    obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(),
               opt.getStratumIndex());
    return 0;
  } catch (std::exception& e) {
    souffle::SignalHandler::instance()->error(e.what());
  }
}

#endif
