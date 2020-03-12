
#include "souffle/CompiledSouffle.h"

extern "C" {
}

namespace souffle {
using namespace ram;
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
} else return false;
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
void insertAll(t_btree_1__0__1& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 1 direct b-tree index [0]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_2__0_1__1__3 {
using t_tuple = Tuple<RamDomain, 2>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1>>;
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
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_2__0_1__1__3& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_2__0_1__3 {
using t_tuple = Tuple<RamDomain, 2>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1>>;
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
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_2__0_1__3& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_4__0_1_2_3__15 {
using t_tuple = Tuple<RamDomain, 4>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3>>;
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
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_4__0_1_2_3__15& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t) const {
context h;
return equalRange_15(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [0,1,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_4__0_1_2_3__7__15 {
using t_tuple = Tuple<RamDomain, 4>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3>>;
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
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_4__0_1_2_3__7__15& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t) const {
context h;
return equalRange_7(t, h);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t) const {
context h;
return equalRange_15(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [0,1,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_3__0_1_2__7 {
using t_tuple = Tuple<RamDomain, 3>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2>>;
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
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_3__0_1_2__7& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t) const {
context h;
return equalRange_7(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 3 direct b-tree index [0,1,2]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_3__0_1_2__3__7 {
using t_tuple = Tuple<RamDomain, 3>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2>>;
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
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_3__0_1_2__3__7& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t) const {
context h;
return equalRange_7(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 3 direct b-tree index [0,1,2]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_5__0_1_2_3_4__31 {
using t_tuple = Tuple<RamDomain, 5>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3,4>>;
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
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[5];
std::copy(ramDomain, ramDomain + 5, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4) {
RamDomain data[5] = {a0,a1,a2,a3,a4};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_5__0_1_2_3_4__31& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_31(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_31(const t_tuple& t) const {
context h;
return equalRange_31(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 5 direct b-tree index [0,1,2,3,4]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};

class Sf_cellular_automata : public SouffleProgram {
private:
static inline bool regex_wrapper(const std::string& pattern, const std::string& text) {
   bool result = false; 
   try { result = std::regex_match(text, std::regex(pattern)); } catch(...) { 
     std::cerr << "warning: wrong pattern provided for match(\"" << pattern << "\",\"" << text << "\").\n";
}
   return result;
}
private:
static inline std::string substr_wrapper(const std::string& str, size_t idx, size_t len) {
   std::string result; 
   try { result = str.substr(idx,len); } catch(...) { 
     std::cerr << "warning: wrong index position provided by substr(\"";
     std::cerr << str << "\"," << (int32_t)idx << "," << (int32_t)len << ") functor.\n";
   } return result;
}
private:
static inline RamDomain wrapper_tonumber(const std::string& str) {
   RamDomain result=0; 
   try { result = stord(str); } catch(...) { 
     std::cerr << "error: wrong string provided by to_number(\"";
     std::cerr << str << "\") functor.\n";
     raise(SIGFPE);
   } return result;
}
public:
// -- initialize symbol table --
SymbolTable symTable
;// -- Table: default
std::unique_ptr<t_btree_1__0__1> rel_1_default = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<0,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_1_default;
// -- Table: parameters
std::unique_ptr<t_btree_1__0__1> rel_2_parameters = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<1,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_2_parameters;
// -- Table: indices
std::unique_ptr<t_btree_1__0__1> rel_3_indices = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<2,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_3_indices;
// -- Table: @delta_indices
std::unique_ptr<t_btree_1__0__1> rel_4_delta_indices = std::make_unique<t_btree_1__0__1>();
// -- Table: @new_indices
std::unique_ptr<t_btree_1__0__1> rel_5_new_indices = std::make_unique<t_btree_1__0__1>();
// -- Table: values
std::unique_ptr<t_btree_2__0_1__1__3> rel_6_values = std::make_unique<t_btree_2__0_1__1__3>();
souffle::RelationWrapper<3,t_btree_2__0_1__1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_6_values;
// -- Table: element
std::unique_ptr<t_btree_2__0_1__1__3> rel_7_element = std::make_unique<t_btree_2__0_1__1__3>();
souffle::RelationWrapper<4,t_btree_2__0_1__1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_7_element;
// -- Table: left
std::unique_ptr<t_btree_2__0_1__3> rel_8_left = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<5,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_8_left;
// -- Table: right
std::unique_ptr<t_btree_2__0_1__1__3> rel_9_right = std::make_unique<t_btree_2__0_1__1__3>();
souffle::RelationWrapper<6,t_btree_2__0_1__1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_9_right;
// -- Table: neighbourhood
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_10_neighbourhood = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<7,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4,1> wrapper_rel_10_neighbourhood;
// -- Table: terminate
std::unique_ptr<t_btree_1__0__1> rel_11_terminate = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<8,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_11_terminate;
// -- Table: transition
std::unique_ptr<t_btree_4__0_1_2_3__7__15> rel_12_transition = std::make_unique<t_btree_4__0_1_2_3__7__15>();
souffle::RelationWrapper<9,t_btree_4__0_1_2_3__7__15,Tuple<RamDomain,4>,4,1> wrapper_rel_12_transition;
// -- Table: prev
std::unique_ptr<t_btree_3__0_1_2__7> rel_13_prev = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<10,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3,1> wrapper_rel_13_prev;
// -- Table: @delta_prev
std::unique_ptr<t_btree_3__0_1_2__7> rel_14_delta_prev = std::make_unique<t_btree_3__0_1_2__7>();
// -- Table: @new_prev
std::unique_ptr<t_btree_3__0_1_2__7> rel_15_new_prev = std::make_unique<t_btree_3__0_1_2__7>();
// -- Table: next
std::unique_ptr<t_btree_3__0_1_2__3__7> rel_16_next = std::make_unique<t_btree_3__0_1_2__3__7>();
souffle::RelationWrapper<11,t_btree_3__0_1_2__3__7,Tuple<RamDomain,3>,3,1> wrapper_rel_16_next;
// -- Table: @delta_next
std::unique_ptr<t_btree_3__0_1_2__3__7> rel_17_delta_next = std::make_unique<t_btree_3__0_1_2__3__7>();
// -- Table: @new_next
std::unique_ptr<t_btree_3__0_1_2__3__7> rel_18_new_next = std::make_unique<t_btree_3__0_1_2__3__7>();
// -- Table: environment
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_19_environment = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<12,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5,1> wrapper_rel_19_environment;
// -- Table: @delta_environment
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_20_delta_environment = std::make_unique<t_btree_5__0_1_2_3_4__31>();
// -- Table: @new_environment
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_21_new_environment = std::make_unique<t_btree_5__0_1_2_3_4__31>();
// -- Table: cell
std::unique_ptr<t_btree_3__0_1_2__3__7> rel_22_cell = std::make_unique<t_btree_3__0_1_2__3__7>();
souffle::RelationWrapper<13,t_btree_3__0_1_2__3__7,Tuple<RamDomain,3>,3,1> wrapper_rel_22_cell;
// -- Table: @delta_cell
std::unique_ptr<t_btree_3__0_1_2__3__7> rel_23_delta_cell = std::make_unique<t_btree_3__0_1_2__3__7>();
// -- Table: @new_cell
std::unique_ptr<t_btree_3__0_1_2__3__7> rel_24_new_cell = std::make_unique<t_btree_3__0_1_2__3__7>();
public:
Sf_cellular_automata() : 
wrapper_rel_1_default(*rel_1_default,symTable,"default",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"null"}}),

wrapper_rel_2_parameters(*rel_2_parameters,symTable,"parameters",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"length"}}),

wrapper_rel_3_indices(*rel_3_indices,symTable,"indices",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"index"}}),

wrapper_rel_6_values(*rel_6_values,symTable,"values",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"index","value"}}),

wrapper_rel_7_element(*rel_7_element,symTable,"element",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"index","value"}}),

wrapper_rel_8_left(*rel_8_left,symTable,"left",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"index","value"}}),

wrapper_rel_9_right(*rel_9_right,symTable,"right",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"index","value"}}),

wrapper_rel_10_neighbourhood(*rel_10_neighbourhood,symTable,"neighbourhood",std::array<const char *,4>{{"i:number","i:number","i:number","i:number"}},std::array<const char *,4>{{"index","left","current","right"}}),

wrapper_rel_11_terminate(*rel_11_terminate,symTable,"terminate",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"time"}}),

wrapper_rel_12_transition(*rel_12_transition,symTable,"transition",std::array<const char *,4>{{"i:number","i:number","i:number","i:number"}},std::array<const char *,4>{{"prev","center","next","value"}}),

wrapper_rel_13_prev(*rel_13_prev,symTable,"prev",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"time","index","value"}}),

wrapper_rel_16_next(*rel_16_next,symTable,"next",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"time","index","value"}}),

wrapper_rel_19_environment(*rel_19_environment,symTable,"environment",std::array<const char *,5>{{"i:number","i:number","i:number","i:number","i:number"}},std::array<const char *,5>{{"time","index","prev","center","next"}}),

wrapper_rel_22_cell(*rel_22_cell,symTable,"cell",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"time","index","value"}}){
addRelation("default",&wrapper_rel_1_default,false,false);
addRelation("parameters",&wrapper_rel_2_parameters,true,false);
addRelation("indices",&wrapper_rel_3_indices,false,true);
addRelation("values",&wrapper_rel_6_values,true,false);
addRelation("element",&wrapper_rel_7_element,false,true);
addRelation("left",&wrapper_rel_8_left,false,false);
addRelation("right",&wrapper_rel_9_right,false,false);
addRelation("neighbourhood",&wrapper_rel_10_neighbourhood,false,true);
addRelation("terminate",&wrapper_rel_11_terminate,true,false);
addRelation("transition",&wrapper_rel_12_transition,false,false);
addRelation("prev",&wrapper_rel_13_prev,false,false);
addRelation("next",&wrapper_rel_16_next,false,false);
addRelation("environment",&wrapper_rel_19_environment,false,true);
addRelation("cell",&wrapper_rel_22_cell,false,true);
}
~Sf_cellular_automata() {
}
private:
void runFunction(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1, bool performIO = false) {
SignalHandler::instance()->set();
std::atomic<size_t> iter(0);

#if defined(_OPENMP)
if (getNumThreads() > 0) {omp_set_num_threads(getNumThreads());}
#endif

// -- query evaluation --
/* BEGIN STRATUM 0 */
[&]() {
SignalHandler::instance()->setMsg(R"_(default(0).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [6:1-6:12])_");
rel_1_default->insert(RamDomain(0));
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./parameters.facts"},{"name","parameters"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_2_parameters);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
SignalHandler::instance()->setMsg(R"_(indices(0).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [19:1-19:12])_");
rel_3_indices->insert(RamDomain(0));
rel_4_delta_indices->insertAll(*rel_3_indices);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(indices((i+1)) :- 
   indices(i),
   parameters(l),
   i >= 0,
   (i+1) < l.
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [20:1-20:60])_");
if(!(rel_2_parameters->empty()) && !(rel_4_delta_indices->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_2_parameters_op_ctxt,rel_2_parameters->createContext());
CREATE_OP_CONTEXT(rel_3_indices_op_ctxt,rel_3_indices->createContext());
CREATE_OP_CONTEXT(rel_4_delta_indices_op_ctxt,rel_4_delta_indices->createContext());
CREATE_OP_CONTEXT(rel_5_new_indices_op_ctxt,rel_5_new_indices->createContext());
for(const auto& env0 : *rel_4_delta_indices) {
if( ((env0[0]) >= (RamDomain(0))) && !(rel_3_indices->contains(Tuple<RamDomain,1>{{(env0[0]) + (RamDomain(1))}},READ_OP_CONTEXT(rel_3_indices_op_ctxt)))) {
for(const auto& env1 : *rel_2_parameters) {
if( (((env0[0]) + (RamDomain(1))) < (env1[0]))) {
if( (((env0[0]) + (RamDomain(1))) < (env1[0]))) {
Tuple<RamDomain,1> tuple{{static_cast<RamDomain>((env0[0]) + (RamDomain(1)))}};
rel_5_new_indices->insert(tuple,READ_OP_CONTEXT(rel_5_new_indices_op_ctxt));
}
break;
}
}
}
}
}
();}
if(rel_5_new_indices->empty()) break;
rel_3_indices->insertAll(*rel_5_new_indices);
std::swap(rel_4_delta_indices, rel_5_new_indices);
rel_5_new_indices->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_4_delta_indices->purge();
if (!isHintsProfilingEnabled()) rel_5_new_indices->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","index"},{"filename","./indices.ans"},{"name","indices"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_3_indices);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_2_parameters->purge();
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./values.facts"},{"name","values"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_6_values);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
SignalHandler::instance()->setMsg(R"_(element(i,NULL) :- 
   indices(i),
   default(NULL),
   !values(i,_).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [25:1-25:62])_");
if(!(rel_1_default->empty()) && !(rel_3_indices->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_default_op_ctxt,rel_1_default->createContext());
CREATE_OP_CONTEXT(rel_3_indices_op_ctxt,rel_3_indices->createContext());
CREATE_OP_CONTEXT(rel_6_values_op_ctxt,rel_6_values->createContext());
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
for(const auto& env0 : *rel_3_indices) {
if( !(!rel_6_values->equalRange_1(Tuple<RamDomain,2>{{env0[0],0}},READ_OP_CONTEXT(rel_6_values_op_ctxt)).empty())) {
for(const auto& env1 : *rel_1_default) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[0])}};
rel_7_element->insert(tuple,READ_OP_CONTEXT(rel_7_element_op_ctxt));
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(element(i,x) :- 
   indices(i),
   values(i,x).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [26:1-26:43])_");
if(!(rel_6_values->empty()) && !(rel_3_indices->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_indices_op_ctxt,rel_3_indices->createContext());
CREATE_OP_CONTEXT(rel_6_values_op_ctxt,rel_6_values->createContext());
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
for(const auto& env0 : *rel_3_indices) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_6_values->equalRange_1(key,READ_OP_CONTEXT(rel_6_values_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}};
rel_7_element->insert(tuple,READ_OP_CONTEXT(rel_7_element_op_ctxt));
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","index\tvalue"},{"filename","./element.ans"},{"name","element"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_7_element);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_6_values->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_3_indices->purge();
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
SignalHandler::instance()->setMsg(R"_(left(i,NULL) :- 
   element(i,_),
   default(NULL),
   !element((i-1),_).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [30:1-30:65])_");
if(!(rel_1_default->empty()) && !(rel_7_element->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_default_op_ctxt,rel_1_default->createContext());
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
CREATE_OP_CONTEXT(rel_8_left_op_ctxt,rel_8_left->createContext());
for(const auto& env0 : *rel_7_element) {
if( !(!rel_7_element->equalRange_1(Tuple<RamDomain,2>{{(env0[0]) - (RamDomain(1)),0}},READ_OP_CONTEXT(rel_7_element_op_ctxt)).empty())) {
for(const auto& env1 : *rel_1_default) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[0])}};
rel_8_left->insert(tuple,READ_OP_CONTEXT(rel_8_left_op_ctxt));
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(left(i,x) :- 
   element( _tmp_0,x),
   element(i,_),
    _tmp_0 = (i-1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [31:1-31:46])_");
if(!(rel_7_element->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
CREATE_OP_CONTEXT(rel_8_left_op_ctxt,rel_8_left->createContext());
for(const auto& env0 : *rel_7_element) {
for(const auto& env1 : *rel_7_element) {
if( ((env0[0]) == ((env1[0]) - (RamDomain(1))))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[1])}};
rel_8_left->insert(tuple,READ_OP_CONTEXT(rel_8_left_op_ctxt));
}
}
}
}
();}
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
SignalHandler::instance()->setMsg(R"_(right(i,NULL) :- 
   element(i,_),
   default(NULL),
   !element((i+1),_).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [35:1-35:66])_");
if(!(rel_1_default->empty()) && !(rel_7_element->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_default_op_ctxt,rel_1_default->createContext());
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
CREATE_OP_CONTEXT(rel_9_right_op_ctxt,rel_9_right->createContext());
for(const auto& env0 : *rel_7_element) {
if( !(!rel_7_element->equalRange_1(Tuple<RamDomain,2>{{(env0[0]) + (RamDomain(1)),0}},READ_OP_CONTEXT(rel_7_element_op_ctxt)).empty())) {
for(const auto& env1 : *rel_1_default) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[0])}};
rel_9_right->insert(tuple,READ_OP_CONTEXT(rel_9_right_op_ctxt));
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(right(i,x) :- 
   element( _tmp_0,x),
   element(i,_),
    _tmp_0 = (i+1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [36:1-36:47])_");
if(!(rel_7_element->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
CREATE_OP_CONTEXT(rel_9_right_op_ctxt,rel_9_right->createContext());
for(const auto& env0 : *rel_7_element) {
for(const auto& env1 : *rel_7_element) {
if( ((env0[0]) == ((env1[0]) + (RamDomain(1))))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[1])}};
rel_9_right->insert(tuple,READ_OP_CONTEXT(rel_9_right_op_ctxt));
}
}
}
}
();}
}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
SignalHandler::instance()->setMsg(R"_(neighbourhood(i,l,c,r) :- 
   left(i,l),
   element(i,c),
   right(i,r).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [42:1-43:42])_");
if(!(rel_9_right->empty()) && !(rel_7_element->empty()) && !(rel_8_left->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
CREATE_OP_CONTEXT(rel_8_left_op_ctxt,rel_8_left->createContext());
CREATE_OP_CONTEXT(rel_9_right_op_ctxt,rel_9_right->createContext());
CREATE_OP_CONTEXT(rel_10_neighbourhood_op_ctxt,rel_10_neighbourhood->createContext());
for(const auto& env0 : *rel_8_left) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_7_element->equalRange_1(key,READ_OP_CONTEXT(rel_7_element_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_9_right->equalRange_1(key,READ_OP_CONTEXT(rel_9_right_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1])}};
rel_10_neighbourhood->insert(tuple,READ_OP_CONTEXT(rel_10_neighbourhood_op_ctxt));
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","index\tleft\tcurrent\tright"},{"filename","./neighbourhood.ans"},{"name","neighbourhood"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_10_neighbourhood);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_8_left->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_9_right->purge();
}();
/* END STRATUM 7 */
/* BEGIN STRATUM 8 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./terminate.facts"},{"name","terminate"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_11_terminate);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 8 */
/* BEGIN STRATUM 9 */
[&]() {
SignalHandler::instance()->setMsg(R"_(transition(0,0,0,0).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [57:1-57:23])_");
rel_12_transition->insert(RamDomain(0),RamDomain(0),RamDomain(0),RamDomain(0));
SignalHandler::instance()->setMsg(R"_(transition(0,0,1,0).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [58:1-58:23])_");
rel_12_transition->insert(RamDomain(0),RamDomain(0),RamDomain(1),RamDomain(0));
SignalHandler::instance()->setMsg(R"_(transition(0,1,0,0).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [59:1-59:23])_");
rel_12_transition->insert(RamDomain(0),RamDomain(1),RamDomain(0),RamDomain(0));
SignalHandler::instance()->setMsg(R"_(transition(0,1,1,1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [60:1-60:23])_");
rel_12_transition->insert(RamDomain(0),RamDomain(1),RamDomain(1),RamDomain(1));
SignalHandler::instance()->setMsg(R"_(transition(1,0,0,0).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [61:1-61:23])_");
rel_12_transition->insert(RamDomain(1),RamDomain(0),RamDomain(0),RamDomain(0));
SignalHandler::instance()->setMsg(R"_(transition(1,0,1,1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [62:1-62:23])_");
rel_12_transition->insert(RamDomain(1),RamDomain(0),RamDomain(1),RamDomain(1));
SignalHandler::instance()->setMsg(R"_(transition(1,1,0,1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [63:1-63:23])_");
rel_12_transition->insert(RamDomain(1),RamDomain(1),RamDomain(0),RamDomain(1));
SignalHandler::instance()->setMsg(R"_(transition(1,1,1,0).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [64:1-64:23])_");
rel_12_transition->insert(RamDomain(1),RamDomain(1),RamDomain(1),RamDomain(0));
}();
/* END STRATUM 9 */
/* BEGIN STRATUM 10 */
[&]() {
rel_14_delta_prev->insertAll(*rel_13_prev);
rel_17_delta_next->insertAll(*rel_16_next);
rel_20_delta_environment->insertAll(*rel_19_environment);
SignalHandler::instance()->setMsg(R"_(cell(0,i,x) :- 
   element(i,x).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [82:1-82:32])_");
if(!(rel_7_element->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
CREATE_OP_CONTEXT(rel_22_cell_op_ctxt,rel_22_cell->createContext());
for(const auto& env0 : *rel_7_element) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(RamDomain(0)),static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}};
rel_22_cell->insert(tuple,READ_OP_CONTEXT(rel_22_cell_op_ctxt));
}
}
();}
rel_23_delta_cell->insertAll(*rel_22_cell);
iter = 0;
for(;;) {
SECTIONS_START;
SECTION_START;
SignalHandler::instance()->setMsg(R"_(prev(t,i,NULL) :- 
   cell(t,i,_),
   default(NULL),
   !element((i-1),_).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [68:1-68:68])_");
if(!(rel_1_default->empty()) && !(rel_23_delta_cell->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_default_op_ctxt,rel_1_default->createContext());
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
CREATE_OP_CONTEXT(rel_13_prev_op_ctxt,rel_13_prev->createContext());
CREATE_OP_CONTEXT(rel_15_new_prev_op_ctxt,rel_15_new_prev->createContext());
CREATE_OP_CONTEXT(rel_23_delta_cell_op_ctxt,rel_23_delta_cell->createContext());
for(const auto& env0 : *rel_23_delta_cell) {
if( !(!rel_7_element->equalRange_1(Tuple<RamDomain,2>{{(env0[1]) - (RamDomain(1)),0}},READ_OP_CONTEXT(rel_7_element_op_ctxt)).empty())) {
for(const auto& env1 : *rel_1_default) {
if( !(rel_13_prev->contains(Tuple<RamDomain,3>{{env0[0],env0[1],env1[0]}},READ_OP_CONTEXT(rel_13_prev_op_ctxt)))) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env1[0])}};
rel_15_new_prev->insert(tuple,READ_OP_CONTEXT(rel_15_new_prev_op_ctxt));
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(prev(t,i,x) :- 
   cell(t, _tmp_0,x),
   element(i,_),
    _tmp_0 = (i-1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [69:1-69:49])_");
if(!(rel_7_element->empty()) && !(rel_23_delta_cell->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
CREATE_OP_CONTEXT(rel_13_prev_op_ctxt,rel_13_prev->createContext());
CREATE_OP_CONTEXT(rel_15_new_prev_op_ctxt,rel_15_new_prev->createContext());
CREATE_OP_CONTEXT(rel_23_delta_cell_op_ctxt,rel_23_delta_cell->createContext());
for(const auto& env0 : *rel_23_delta_cell) {
for(const auto& env1 : *rel_7_element) {
if( ((env0[1]) == ((env1[0]) - (RamDomain(1)))) && !(rel_13_prev->contains(Tuple<RamDomain,3>{{env0[0],env1[0],env0[2]}},READ_OP_CONTEXT(rel_13_prev_op_ctxt)))) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[2])}};
rel_15_new_prev->insert(tuple,READ_OP_CONTEXT(rel_15_new_prev_op_ctxt));
}
}
}
}
();}
SECTION_END
SECTION_START;
SignalHandler::instance()->setMsg(R"_(next(t,i,NULL) :- 
   cell(t,i,_),
   default(NULL),
   !element((i+1),_).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [73:1-73:68])_");
if(!(rel_1_default->empty()) && !(rel_23_delta_cell->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_default_op_ctxt,rel_1_default->createContext());
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
CREATE_OP_CONTEXT(rel_16_next_op_ctxt,rel_16_next->createContext());
CREATE_OP_CONTEXT(rel_18_new_next_op_ctxt,rel_18_new_next->createContext());
CREATE_OP_CONTEXT(rel_23_delta_cell_op_ctxt,rel_23_delta_cell->createContext());
for(const auto& env0 : *rel_23_delta_cell) {
if( !(!rel_7_element->equalRange_1(Tuple<RamDomain,2>{{(env0[1]) + (RamDomain(1)),0}},READ_OP_CONTEXT(rel_7_element_op_ctxt)).empty())) {
for(const auto& env1 : *rel_1_default) {
if( !(rel_16_next->contains(Tuple<RamDomain,3>{{env0[0],env0[1],env1[0]}},READ_OP_CONTEXT(rel_16_next_op_ctxt)))) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env1[0])}};
rel_18_new_next->insert(tuple,READ_OP_CONTEXT(rel_18_new_next_op_ctxt));
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(next(t,i,x) :- 
   cell(t, _tmp_0,x),
   element(i,_),
    _tmp_0 = (i+1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [74:1-74:49])_");
if(!(rel_7_element->empty()) && !(rel_23_delta_cell->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_7_element_op_ctxt,rel_7_element->createContext());
CREATE_OP_CONTEXT(rel_16_next_op_ctxt,rel_16_next->createContext());
CREATE_OP_CONTEXT(rel_18_new_next_op_ctxt,rel_18_new_next->createContext());
CREATE_OP_CONTEXT(rel_23_delta_cell_op_ctxt,rel_23_delta_cell->createContext());
for(const auto& env0 : *rel_23_delta_cell) {
for(const auto& env1 : *rel_7_element) {
if( ((env0[1]) == ((env1[0]) + (RamDomain(1)))) && !(rel_16_next->contains(Tuple<RamDomain,3>{{env0[0],env1[0],env0[2]}},READ_OP_CONTEXT(rel_16_next_op_ctxt)))) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[2])}};
rel_18_new_next->insert(tuple,READ_OP_CONTEXT(rel_18_new_next_op_ctxt));
}
}
}
}
();}
SECTION_END
SECTION_START;
SignalHandler::instance()->setMsg(R"_(environment(t,i,l,c,r) :- 
   prev(t,i,l),
   cell(t,i,c),
   next(t,i,r).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [90:1-91:47])_");
if(!(rel_16_next->empty()) && !(rel_22_cell->empty()) && !(rel_14_delta_prev->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_17_delta_next_op_ctxt,rel_17_delta_next->createContext());
CREATE_OP_CONTEXT(rel_14_delta_prev_op_ctxt,rel_14_delta_prev->createContext());
CREATE_OP_CONTEXT(rel_16_next_op_ctxt,rel_16_next->createContext());
CREATE_OP_CONTEXT(rel_23_delta_cell_op_ctxt,rel_23_delta_cell->createContext());
CREATE_OP_CONTEXT(rel_21_new_environment_op_ctxt,rel_21_new_environment->createContext());
CREATE_OP_CONTEXT(rel_19_environment_op_ctxt,rel_19_environment->createContext());
CREATE_OP_CONTEXT(rel_22_cell_op_ctxt,rel_22_cell->createContext());
for(const auto& env0 : *rel_14_delta_prev) {
const Tuple<RamDomain,3> key{{env0[0],env0[1],0}};
auto range = rel_22_cell->equalRange_3(key,READ_OP_CONTEXT(rel_22_cell_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_23_delta_cell->contains(Tuple<RamDomain,3>{{env0[0],env0[1],env1[2]}},READ_OP_CONTEXT(rel_23_delta_cell_op_ctxt)))) {
const Tuple<RamDomain,3> key{{env0[0],env0[1],0}};
auto range = rel_16_next->equalRange_3(key,READ_OP_CONTEXT(rel_16_next_op_ctxt));
for(const auto& env2 : range) {
if( !(rel_19_environment->contains(Tuple<RamDomain,5>{{env0[0],env0[1],env0[2],env1[2],env2[2]}},READ_OP_CONTEXT(rel_19_environment_op_ctxt))) && !(rel_17_delta_next->contains(Tuple<RamDomain,3>{{env0[0],env0[1],env2[2]}},READ_OP_CONTEXT(rel_17_delta_next_op_ctxt)))) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env2[2])}};
rel_21_new_environment->insert(tuple,READ_OP_CONTEXT(rel_21_new_environment_op_ctxt));
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(environment(t,i,l,c,r) :- 
   prev(t,i,l),
   cell(t,i,c),
   next(t,i,r).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [90:1-91:47])_");
if(!(rel_16_next->empty()) && !(rel_23_delta_cell->empty()) && !(rel_13_prev->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_17_delta_next_op_ctxt,rel_17_delta_next->createContext());
CREATE_OP_CONTEXT(rel_13_prev_op_ctxt,rel_13_prev->createContext());
CREATE_OP_CONTEXT(rel_16_next_op_ctxt,rel_16_next->createContext());
CREATE_OP_CONTEXT(rel_23_delta_cell_op_ctxt,rel_23_delta_cell->createContext());
CREATE_OP_CONTEXT(rel_21_new_environment_op_ctxt,rel_21_new_environment->createContext());
CREATE_OP_CONTEXT(rel_19_environment_op_ctxt,rel_19_environment->createContext());
for(const auto& env0 : *rel_13_prev) {
const Tuple<RamDomain,3> key{{env0[0],env0[1],0}};
auto range = rel_23_delta_cell->equalRange_3(key,READ_OP_CONTEXT(rel_23_delta_cell_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,3> key{{env0[0],env0[1],0}};
auto range = rel_16_next->equalRange_3(key,READ_OP_CONTEXT(rel_16_next_op_ctxt));
for(const auto& env2 : range) {
if( !(rel_19_environment->contains(Tuple<RamDomain,5>{{env0[0],env0[1],env0[2],env1[2],env2[2]}},READ_OP_CONTEXT(rel_19_environment_op_ctxt))) && !(rel_17_delta_next->contains(Tuple<RamDomain,3>{{env0[0],env0[1],env2[2]}},READ_OP_CONTEXT(rel_17_delta_next_op_ctxt)))) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env2[2])}};
rel_21_new_environment->insert(tuple,READ_OP_CONTEXT(rel_21_new_environment_op_ctxt));
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(environment(t,i,l,c,r) :- 
   prev(t,i,l),
   cell(t,i,c),
   next(t,i,r).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [90:1-91:47])_");
if(!(rel_17_delta_next->empty()) && !(rel_22_cell->empty()) && !(rel_13_prev->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_17_delta_next_op_ctxt,rel_17_delta_next->createContext());
CREATE_OP_CONTEXT(rel_13_prev_op_ctxt,rel_13_prev->createContext());
CREATE_OP_CONTEXT(rel_21_new_environment_op_ctxt,rel_21_new_environment->createContext());
CREATE_OP_CONTEXT(rel_19_environment_op_ctxt,rel_19_environment->createContext());
CREATE_OP_CONTEXT(rel_22_cell_op_ctxt,rel_22_cell->createContext());
for(const auto& env0 : *rel_13_prev) {
const Tuple<RamDomain,3> key{{env0[0],env0[1],0}};
auto range = rel_22_cell->equalRange_3(key,READ_OP_CONTEXT(rel_22_cell_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,3> key{{env0[0],env0[1],0}};
auto range = rel_17_delta_next->equalRange_3(key,READ_OP_CONTEXT(rel_17_delta_next_op_ctxt));
for(const auto& env2 : range) {
if( !(rel_19_environment->contains(Tuple<RamDomain,5>{{env0[0],env0[1],env0[2],env1[2],env2[2]}},READ_OP_CONTEXT(rel_19_environment_op_ctxt)))) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env2[2])}};
rel_21_new_environment->insert(tuple,READ_OP_CONTEXT(rel_21_new_environment_op_ctxt));
}
}
}
}
}
();}
SECTION_END
SECTION_START;
SignalHandler::instance()->setMsg(R"_(cell((t+1),i,x) :- 
   environment(t,i,l,c,r),
   transition(l,c,r,x),
   !terminate(t).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cellular_automata/cellular_automata.dl [85:1-85:86])_");
if(!(rel_12_transition->empty()) && !(rel_20_delta_environment->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_11_terminate_op_ctxt,rel_11_terminate->createContext());
CREATE_OP_CONTEXT(rel_12_transition_op_ctxt,rel_12_transition->createContext());
CREATE_OP_CONTEXT(rel_20_delta_environment_op_ctxt,rel_20_delta_environment->createContext());
CREATE_OP_CONTEXT(rel_22_cell_op_ctxt,rel_22_cell->createContext());
CREATE_OP_CONTEXT(rel_24_new_cell_op_ctxt,rel_24_new_cell->createContext());
for(const auto& env0 : *rel_20_delta_environment) {
if( !(rel_11_terminate->contains(Tuple<RamDomain,1>{{env0[0]}},READ_OP_CONTEXT(rel_11_terminate_op_ctxt)))) {
const Tuple<RamDomain,4> key{{env0[2],env0[3],env0[4],0}};
auto range = rel_12_transition->equalRange_7(key,READ_OP_CONTEXT(rel_12_transition_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_22_cell->contains(Tuple<RamDomain,3>{{(env0[0]) + (RamDomain(1)),env0[1],env1[3]}},READ_OP_CONTEXT(rel_22_cell_op_ctxt)))) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>((env0[0]) + (RamDomain(1))),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env1[3])}};
rel_24_new_cell->insert(tuple,READ_OP_CONTEXT(rel_24_new_cell_op_ctxt));
}
}
}
}
}
();}
SECTION_END
SECTIONS_END;
if(rel_15_new_prev->empty() && rel_18_new_next->empty() && rel_21_new_environment->empty() && rel_24_new_cell->empty()) break;
rel_13_prev->insertAll(*rel_15_new_prev);
std::swap(rel_14_delta_prev, rel_15_new_prev);
rel_15_new_prev->purge();
rel_16_next->insertAll(*rel_18_new_next);
std::swap(rel_17_delta_next, rel_18_new_next);
rel_18_new_next->purge();
rel_19_environment->insertAll(*rel_21_new_environment);
std::swap(rel_20_delta_environment, rel_21_new_environment);
rel_21_new_environment->purge();
rel_22_cell->insertAll(*rel_24_new_cell);
std::swap(rel_23_delta_cell, rel_24_new_cell);
rel_24_new_cell->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_14_delta_prev->purge();
if (!isHintsProfilingEnabled()) rel_15_new_prev->purge();
if (!isHintsProfilingEnabled()) rel_17_delta_next->purge();
if (!isHintsProfilingEnabled()) rel_18_new_next->purge();
if (!isHintsProfilingEnabled()) rel_20_delta_environment->purge();
if (!isHintsProfilingEnabled()) rel_21_new_environment->purge();
if (!isHintsProfilingEnabled()) rel_23_delta_cell->purge();
if (!isHintsProfilingEnabled()) rel_24_new_cell->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","time\tindex\tprev\tcenter\tnext"},{"filename","./environment.ans"},{"name","environment"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_19_environment);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","time\tindex\tvalue"},{"filename","./cell.ans"},{"name","cell"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_cell);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_1_default->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_7_element->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_12_transition->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_11_terminate->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_13_prev->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_16_next->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_19_environment->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_22_cell->purge();
}();
/* END STRATUM 10 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_default:\n";
rel_1_default->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_parameters:\n";
rel_2_parameters->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_indices:\n";
rel_3_indices->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_delta_indices:\n";
rel_4_delta_indices->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_new_indices:\n";
rel_5_new_indices->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_values:\n";
rel_6_values->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_element:\n";
rel_7_element->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_left:\n";
rel_8_left->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_right:\n";
rel_9_right->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_neighbourhood:\n";
rel_10_neighbourhood->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_terminate:\n";
rel_11_terminate->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_transition:\n";
rel_12_transition->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_prev:\n";
rel_13_prev->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_delta_prev:\n";
rel_14_delta_prev->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_new_prev:\n";
rel_15_new_prev->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_next:\n";
rel_16_next->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_delta_next:\n";
rel_17_delta_next->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_new_next:\n";
rel_18_new_next->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_19_environment:\n";
rel_19_environment->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_20_delta_environment:\n";
rel_20_delta_environment->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_21_new_environment:\n";
rel_21_new_environment->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_22_cell:\n";
rel_22_cell->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_23_delta_cell:\n";
rel_23_delta_cell->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_24_new_cell:\n";
rel_24_new_cell->printHintStatistics(std::cout,"  ");
std::cout << "\n";
}
SignalHandler::instance()->reset();
}
public:
void run(size_t stratumIndex = (size_t) -1) override { runFunction(".", ".", stratumIndex, false); }
public:
void runAll(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1) override { runFunction(inputDirectory, outputDirectory, stratumIndex, true);
}
public:
void printAll(std::string outputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","index"},{"filename","./indices.ans"},{"name","indices"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_3_indices);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","index\tvalue"},{"filename","./element.ans"},{"name","element"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_7_element);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","index\tleft\tcurrent\tright"},{"filename","./neighbourhood.ans"},{"name","neighbourhood"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_10_neighbourhood);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","time\tindex\tprev\tcenter\tnext"},{"filename","./environment.ans"},{"name","environment"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_19_environment);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","time\tindex\tvalue"},{"filename","./cell.ans"},{"name","cell"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_cell);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./parameters.facts"},{"name","parameters"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_2_parameters);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./values.facts"},{"name","values"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_6_values);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./terminate.facts"},{"name","terminate"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_11_terminate);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_parameters");
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_2_parameters);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_6_values");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_6_values);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_11_terminate");
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_11_terminate);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_indices");
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_3_indices);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_7_element");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_7_element);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_10_neighbourhood");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_10_neighbourhood);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_19_environment");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_19_environment);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_22_cell");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_cell);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
};
SouffleProgram *newInstance_cellular_automata(){return new Sf_cellular_automata;}
SymbolTable *getST_cellular_automata(SouffleProgram *p){return &reinterpret_cast<Sf_cellular_automata*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_cellular_automata: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_cellular_automata();
};
public:
factory_Sf_cellular_automata() : ProgramFactory("cellular_automata"){}
};
static factory_Sf_cellular_automata __factory_Sf_cellular_automata_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(cellular_automata.dl)",
R"(.)",
R"(.)",
false,
R"()",
1,
-1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_cellular_automata obj;
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
