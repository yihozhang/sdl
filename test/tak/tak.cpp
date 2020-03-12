
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
struct t_btree_5__1_0_2_3_4__2__3__7__31 {
using t_tuple = Tuple<RamDomain, 5>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1,0,2,3,4>>;
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
void insertAll(t_btree_5__1_0_2_3_4__2__3__7__31& other) {
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
range<t_ind_0::iterator> equalRange_2(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_2(const t_tuple& t) const {
context h;
return equalRange_2(t, h);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t) const {
context h;
return equalRange_7(t, h);
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
o << prefix << "arity 5 direct b-tree index [1,0,2,3,4]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_5__0_1_2_3_4__3__7__31 {
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
void insertAll(t_btree_5__0_1_2_3_4__3__7__31& other) {
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
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t) const {
context h;
return equalRange_7(t, h);
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

class Sf_tak : public SouffleProgram {
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
;// -- Table: high1
std::unique_ptr<t_btree_1__0__1> rel_1_high1 = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<0,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_1_high1;
// -- Table: high2
std::unique_ptr<t_btree_1__0__1> rel_2_high2 = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<1,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_2_high2;
// -- Table: low1
std::unique_ptr<t_btree_1__0__1> rel_3_low1 = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<2,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_3_low1;
// -- Table: natural
std::unique_ptr<t_btree_1__0__1> rel_4_natural = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<3,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_4_natural;
// -- Table: @delta_natural
std::unique_ptr<t_btree_1__0__1> rel_5_delta_natural = std::make_unique<t_btree_1__0__1>();
// -- Table: @new_natural
std::unique_ptr<t_btree_1__0__1> rel_6_new_natural = std::make_unique<t_btree_1__0__1>();
// -- Table: tak
std::unique_ptr<t_btree_5__1_0_2_3_4__2__3__7__31> rel_7_tak = std::make_unique<t_btree_5__1_0_2_3_4__2__3__7__31>();
souffle::RelationWrapper<4,t_btree_5__1_0_2_3_4__2__3__7__31,Tuple<RamDomain,5>,5,1> wrapper_rel_7_tak;
// -- Table: @delta_tak
std::unique_ptr<t_btree_5__0_1_2_3_4__3__7__31> rel_8_delta_tak = std::make_unique<t_btree_5__0_1_2_3_4__3__7__31>();
// -- Table: @new_tak
std::unique_ptr<t_btree_5__0_1_2_3_4__3__7__31> rel_9_new_tak = std::make_unique<t_btree_5__0_1_2_3_4__3__7__31>();
// -- Table: low2
std::unique_ptr<t_btree_1__0__1> rel_10_low2 = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<5,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_10_low2;
// -- Table: query
std::unique_ptr<t_btree_2__0_1__3> rel_11_query = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<6,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_11_query;
public:
Sf_tak() : 
wrapper_rel_1_high1(*rel_1_high1,symTable,"high1",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"x"}}),

wrapper_rel_2_high2(*rel_2_high2,symTable,"high2",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"x"}}),

wrapper_rel_3_low1(*rel_3_low1,symTable,"low1",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"x"}}),

wrapper_rel_4_natural(*rel_4_natural,symTable,"natural",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"N"}}),

wrapper_rel_7_tak(*rel_7_tak,symTable,"tak",std::array<const char *,5>{{"i:number","i:number","i:number","i:number","i:number"}},std::array<const char *,5>{{"X","Y","Z","V","Q"}}),

wrapper_rel_10_low2(*rel_10_low2,symTable,"low2",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"x"}}),

wrapper_rel_11_query(*rel_11_query,symTable,"query",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"N","Q"}}){
addRelation("high1",&wrapper_rel_1_high1,true,false);
addRelation("high2",&wrapper_rel_2_high2,true,false);
addRelation("low1",&wrapper_rel_3_low1,true,false);
addRelation("natural",&wrapper_rel_4_natural,false,false);
addRelation("tak",&wrapper_rel_7_tak,false,false);
addRelation("low2",&wrapper_rel_10_low2,true,false);
addRelation("query",&wrapper_rel_11_query,false,true);
}
~Sf_tak() {
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
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./high1.facts"},{"name","high1"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_1_high1);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./high2.facts"},{"name","high2"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_2_high2);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./low1.facts"},{"name","low1"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_3_low1);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
SignalHandler::instance()->setMsg(R"_(natural(x) :- 
   low1(x).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tak/tak.dl [19:1-19:23])_");
if(!(rel_3_low1->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_low1_op_ctxt,rel_3_low1->createContext());
CREATE_OP_CONTEXT(rel_4_natural_op_ctxt,rel_4_natural->createContext());
for(const auto& env0 : *rel_3_low1) {
Tuple<RamDomain,1> tuple{{static_cast<RamDomain>(env0[0])}};
rel_4_natural->insert(tuple,READ_OP_CONTEXT(rel_4_natural_op_ctxt));
}
}
();}
rel_5_delta_natural->insertAll(*rel_4_natural);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(natural((n+1)) :- 
   natural(n),
   high1(h),
   n < h.
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tak/tak.dl [21:1-21:45])_");
if(!(rel_1_high1->empty()) && !(rel_5_delta_natural->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_4_natural_op_ctxt,rel_4_natural->createContext());
CREATE_OP_CONTEXT(rel_5_delta_natural_op_ctxt,rel_5_delta_natural->createContext());
CREATE_OP_CONTEXT(rel_6_new_natural_op_ctxt,rel_6_new_natural->createContext());
CREATE_OP_CONTEXT(rel_1_high1_op_ctxt,rel_1_high1->createContext());
for(const auto& env0 : *rel_5_delta_natural) {
if( !(rel_4_natural->contains(Tuple<RamDomain,1>{{(env0[0]) + (RamDomain(1))}},READ_OP_CONTEXT(rel_4_natural_op_ctxt)))) {
for(const auto& env1 : *rel_1_high1) {
if( ((env0[0]) < (env1[0]))) {
if( ((env0[0]) < (env1[0]))) {
Tuple<RamDomain,1> tuple{{static_cast<RamDomain>((env0[0]) + (RamDomain(1)))}};
rel_6_new_natural->insert(tuple,READ_OP_CONTEXT(rel_6_new_natural_op_ctxt));
}
break;
}
}
}
}
}
();}
if(rel_6_new_natural->empty()) break;
rel_4_natural->insertAll(*rel_6_new_natural);
std::swap(rel_5_delta_natural, rel_6_new_natural);
rel_6_new_natural->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_5_delta_natural->purge();
if (!isHintsProfilingEnabled()) rel_6_new_natural->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_3_low1->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_1_high1->purge();
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
SignalHandler::instance()->setMsg(R"_(tak(X,Y,Z,Y,0) :- 
   natural(X),
   natural(Y),
   natural(Z),
   Y >= X.
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tak/tak.dl [4:1-4:62])_");
if(!(rel_4_natural->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_4_natural_op_ctxt,rel_4_natural->createContext());
CREATE_OP_CONTEXT(rel_7_tak_op_ctxt,rel_7_tak->createContext());
for(const auto& env0 : *rel_4_natural) {
for(const auto& env1 : *rel_4_natural) {
if( ((env1[0]) >= (env0[0]))) {
for(const auto& env2 : *rel_4_natural) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(0))}};
rel_7_tak->insert(tuple,READ_OP_CONTEXT(rel_7_tak_op_ctxt));
}
}
}
}
}
();}
rel_8_delta_tak->insertAll(*rel_7_tak);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(tak(X,Y,Z,V,((((Q1+Q2)+Q3)+Q4)+1)) :- 
   tak( _tmp_0,Y,Z,V1,Q1),
   tak( _tmp_1,Z,X,V2,Q2),
   tak( _tmp_2,X,Y,V3,Q3),
   tak(V1,V2,V3,V,Q4),
   Y < X,
    _tmp_0 = (X-1),
    _tmp_1 = (Y-1),
    _tmp_2 = (Z-1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tak/tak.dl [5:1-6:57])_");
if(!(rel_8_delta_tak->empty()) && !(rel_7_tak->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_8_delta_tak_op_ctxt,rel_8_delta_tak->createContext());
CREATE_OP_CONTEXT(rel_9_new_tak_op_ctxt,rel_9_new_tak->createContext());
CREATE_OP_CONTEXT(rel_7_tak_op_ctxt,rel_7_tak->createContext());
for(const auto& env0 : *rel_8_delta_tak) {
const Tuple<RamDomain,5> key{{(env0[1]) - (RamDomain(1)),env0[2],0,0,0}};
auto range = rel_7_tak->equalRange_3(key,READ_OP_CONTEXT(rel_7_tak_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_8_delta_tak->contains(Tuple<RamDomain,5>{{env1[0],env0[2],env1[2],env1[3],env1[4]}},READ_OP_CONTEXT(rel_8_delta_tak_op_ctxt))) && ((env0[1]) < (env1[2])) && ((env0[0]) == ((env1[2]) - (RamDomain(1))))) {
const Tuple<RamDomain,5> key{{(env0[2]) - (RamDomain(1)),env1[2],env0[1],0,0}};
auto range = rel_7_tak->equalRange_7(key,READ_OP_CONTEXT(rel_7_tak_op_ctxt));
for(const auto& env2 : range) {
if( !(rel_8_delta_tak->contains(Tuple<RamDomain,5>{{env2[0],env1[2],env0[1],env2[3],env2[4]}},READ_OP_CONTEXT(rel_8_delta_tak_op_ctxt)))) {
const Tuple<RamDomain,5> key{{env0[3],env1[3],env2[3],0,0}};
auto range = rel_7_tak->equalRange_7(key,READ_OP_CONTEXT(rel_7_tak_op_ctxt));
for(const auto& env3 : range) {
if( !(rel_7_tak->contains(Tuple<RamDomain,5>{{env1[2],env0[1],env0[2],env3[3],((((env0[4]) + (env1[4])) + (env2[4])) + (env3[4])) + (RamDomain(1))}},READ_OP_CONTEXT(rel_7_tak_op_ctxt))) && !(rel_8_delta_tak->contains(Tuple<RamDomain,5>{{env0[3],env1[3],env2[3],env3[3],env3[4]}},READ_OP_CONTEXT(rel_8_delta_tak_op_ctxt)))) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(((((env0[4]) + (env1[4])) + (env2[4])) + (env3[4])) + (RamDomain(1)))}};
rel_9_new_tak->insert(tuple,READ_OP_CONTEXT(rel_9_new_tak_op_ctxt));
}
}
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(tak(X,Y,Z,V,((((Q1+Q2)+Q3)+Q4)+1)) :- 
   tak( _tmp_0,Y,Z,V1,Q1),
   tak( _tmp_1,Z,X,V2,Q2),
   tak( _tmp_2,X,Y,V3,Q3),
   tak(V1,V2,V3,V,Q4),
   Y < X,
    _tmp_0 = (X-1),
    _tmp_1 = (Y-1),
    _tmp_2 = (Z-1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tak/tak.dl [5:1-6:57])_");
if(!(rel_8_delta_tak->empty()) && !(rel_7_tak->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_8_delta_tak_op_ctxt,rel_8_delta_tak->createContext());
CREATE_OP_CONTEXT(rel_9_new_tak_op_ctxt,rel_9_new_tak->createContext());
CREATE_OP_CONTEXT(rel_7_tak_op_ctxt,rel_7_tak->createContext());
for(const auto& env0 : *rel_7_tak) {
const Tuple<RamDomain,5> key{{(env0[1]) - (RamDomain(1)),env0[2],0,0,0}};
auto range = rel_8_delta_tak->equalRange_3(key,READ_OP_CONTEXT(rel_8_delta_tak_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[1]) < (env1[2])) && ((env0[0]) == ((env1[2]) - (RamDomain(1))))) {
const Tuple<RamDomain,5> key{{(env0[2]) - (RamDomain(1)),env1[2],env0[1],0,0}};
auto range = rel_7_tak->equalRange_7(key,READ_OP_CONTEXT(rel_7_tak_op_ctxt));
for(const auto& env2 : range) {
if( !(rel_8_delta_tak->contains(Tuple<RamDomain,5>{{env2[0],env1[2],env0[1],env2[3],env2[4]}},READ_OP_CONTEXT(rel_8_delta_tak_op_ctxt)))) {
const Tuple<RamDomain,5> key{{env0[3],env1[3],env2[3],0,0}};
auto range = rel_7_tak->equalRange_7(key,READ_OP_CONTEXT(rel_7_tak_op_ctxt));
for(const auto& env3 : range) {
if( !(rel_7_tak->contains(Tuple<RamDomain,5>{{env1[2],env0[1],env0[2],env3[3],((((env0[4]) + (env1[4])) + (env2[4])) + (env3[4])) + (RamDomain(1))}},READ_OP_CONTEXT(rel_7_tak_op_ctxt))) && !(rel_8_delta_tak->contains(Tuple<RamDomain,5>{{env0[3],env1[3],env2[3],env3[3],env3[4]}},READ_OP_CONTEXT(rel_8_delta_tak_op_ctxt)))) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(((((env0[4]) + (env1[4])) + (env2[4])) + (env3[4])) + (RamDomain(1)))}};
rel_9_new_tak->insert(tuple,READ_OP_CONTEXT(rel_9_new_tak_op_ctxt));
}
}
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(tak(X,Y,Z,V,((((Q1+Q2)+Q3)+Q4)+1)) :- 
   tak( _tmp_0,Y,Z,V1,Q1),
   tak( _tmp_1,Z,X,V2,Q2),
   tak( _tmp_2,X,Y,V3,Q3),
   tak(V1,V2,V3,V,Q4),
   Y < X,
    _tmp_0 = (X-1),
    _tmp_1 = (Y-1),
    _tmp_2 = (Z-1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tak/tak.dl [5:1-6:57])_");
if(!(rel_8_delta_tak->empty()) && !(rel_7_tak->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_8_delta_tak_op_ctxt,rel_8_delta_tak->createContext());
CREATE_OP_CONTEXT(rel_9_new_tak_op_ctxt,rel_9_new_tak->createContext());
CREATE_OP_CONTEXT(rel_7_tak_op_ctxt,rel_7_tak->createContext());
for(const auto& env0 : *rel_7_tak) {
const Tuple<RamDomain,5> key{{(env0[1]) - (RamDomain(1)),env0[2],0,0,0}};
auto range = rel_7_tak->equalRange_3(key,READ_OP_CONTEXT(rel_7_tak_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[1]) < (env1[2])) && ((env0[0]) == ((env1[2]) - (RamDomain(1))))) {
const Tuple<RamDomain,5> key{{(env0[2]) - (RamDomain(1)),env1[2],env0[1],0,0}};
auto range = rel_8_delta_tak->equalRange_7(key,READ_OP_CONTEXT(rel_8_delta_tak_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,5> key{{env0[3],env1[3],env2[3],0,0}};
auto range = rel_7_tak->equalRange_7(key,READ_OP_CONTEXT(rel_7_tak_op_ctxt));
for(const auto& env3 : range) {
if( !(rel_7_tak->contains(Tuple<RamDomain,5>{{env1[2],env0[1],env0[2],env3[3],((((env0[4]) + (env1[4])) + (env2[4])) + (env3[4])) + (RamDomain(1))}},READ_OP_CONTEXT(rel_7_tak_op_ctxt))) && !(rel_8_delta_tak->contains(Tuple<RamDomain,5>{{env0[3],env1[3],env2[3],env3[3],env3[4]}},READ_OP_CONTEXT(rel_8_delta_tak_op_ctxt)))) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(((((env0[4]) + (env1[4])) + (env2[4])) + (env3[4])) + (RamDomain(1)))}};
rel_9_new_tak->insert(tuple,READ_OP_CONTEXT(rel_9_new_tak_op_ctxt));
}
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(tak(X,Y,Z,V,((((Q1+Q2)+Q3)+Q4)+1)) :- 
   tak( _tmp_0,Y,Z,V1,Q1),
   tak( _tmp_1,Z,X,V2,Q2),
   tak( _tmp_2,X,Y,V3,Q3),
   tak(V1,V2,V3,V,Q4),
   Y < X,
    _tmp_0 = (X-1),
    _tmp_1 = (Y-1),
    _tmp_2 = (Z-1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tak/tak.dl [5:1-6:57])_");
if(!(rel_7_tak->empty()) && !(rel_8_delta_tak->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_8_delta_tak_op_ctxt,rel_8_delta_tak->createContext());
CREATE_OP_CONTEXT(rel_9_new_tak_op_ctxt,rel_9_new_tak->createContext());
CREATE_OP_CONTEXT(rel_7_tak_op_ctxt,rel_7_tak->createContext());
for(const auto& env0 : *rel_7_tak) {
const Tuple<RamDomain,5> key{{(env0[1]) - (RamDomain(1)),env0[2],0,0,0}};
auto range = rel_7_tak->equalRange_3(key,READ_OP_CONTEXT(rel_7_tak_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[1]) < (env1[2])) && ((env0[0]) == ((env1[2]) - (RamDomain(1))))) {
const Tuple<RamDomain,5> key{{(env0[2]) - (RamDomain(1)),env1[2],env0[1],0,0}};
auto range = rel_7_tak->equalRange_7(key,READ_OP_CONTEXT(rel_7_tak_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,5> key{{env0[3],env1[3],env2[3],0,0}};
auto range = rel_8_delta_tak->equalRange_7(key,READ_OP_CONTEXT(rel_8_delta_tak_op_ctxt));
for(const auto& env3 : range) {
if( !(rel_7_tak->contains(Tuple<RamDomain,5>{{env1[2],env0[1],env0[2],env3[3],((((env0[4]) + (env1[4])) + (env2[4])) + (env3[4])) + (RamDomain(1))}},READ_OP_CONTEXT(rel_7_tak_op_ctxt)))) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(((((env0[4]) + (env1[4])) + (env2[4])) + (env3[4])) + (RamDomain(1)))}};
rel_9_new_tak->insert(tuple,READ_OP_CONTEXT(rel_9_new_tak_op_ctxt));
}
}
}
}
}
}
}
();}
if(rel_9_new_tak->empty()) break;
rel_7_tak->insertAll(*rel_9_new_tak);
std::swap(rel_8_delta_tak, rel_9_new_tak);
rel_9_new_tak->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_8_delta_tak->purge();
if (!isHintsProfilingEnabled()) rel_9_new_tak->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_4_natural->purge();
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./low2.facts"},{"name","low2"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_10_low2);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
SignalHandler::instance()->setMsg(R"_(query(N,Q) :- 
   tak(N,0, _tmp_0,_,Q),
   low2(l),
   high2(h),
   N >= l,
   N < h,
    _tmp_0 = (N+1).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tak/tak.dl [29:1-29:71])_");
if(!(rel_2_high2->empty()) && !(rel_10_low2->empty()) && !(rel_7_tak->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_10_low2_op_ctxt,rel_10_low2->createContext());
CREATE_OP_CONTEXT(rel_2_high2_op_ctxt,rel_2_high2->createContext());
CREATE_OP_CONTEXT(rel_7_tak_op_ctxt,rel_7_tak->createContext());
CREATE_OP_CONTEXT(rel_11_query_op_ctxt,rel_11_query->createContext());
const Tuple<RamDomain,5> key{{0,RamDomain(0),0,0,0}};
auto range = rel_7_tak->equalRange_2(key,READ_OP_CONTEXT(rel_7_tak_op_ctxt));
for(const auto& env0 : range) {
if( ((env0[2]) == ((env0[0]) + (RamDomain(1))))) {
for(const auto& env1 : *rel_10_low2) {
if( ((env0[0]) >= (env1[0]))) {
if( ((env0[0]) >= (env1[0]))) {
for(const auto& env2 : *rel_2_high2) {
if( ((env0[0]) < (env2[0]))) {
if( ((env0[0]) < (env2[0]))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[4])}};
rel_11_query->insert(tuple,READ_OP_CONTEXT(rel_11_query_op_ctxt));
}
break;
}
}
}
break;
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","N\tQ"},{"filename","./query.ans"},{"name","query"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_11_query);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_7_tak->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_2_high2->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_10_low2->purge();
}();
/* END STRATUM 6 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_high1:\n";
rel_1_high1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_high2:\n";
rel_2_high2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_low1:\n";
rel_3_low1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_natural:\n";
rel_4_natural->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_delta_natural:\n";
rel_5_delta_natural->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_new_natural:\n";
rel_6_new_natural->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_tak:\n";
rel_7_tak->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_delta_tak:\n";
rel_8_delta_tak->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_new_tak:\n";
rel_9_new_tak->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_low2:\n";
rel_10_low2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_query:\n";
rel_11_query->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","N\tQ"},{"filename","./query.ans"},{"name","query"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_11_query);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./high1.facts"},{"name","high1"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_1_high1);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./high2.facts"},{"name","high2"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_2_high2);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./low1.facts"},{"name","low1"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_3_low1);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./low2.facts"},{"name","low2"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_10_low2);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_high1");
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_1_high1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_high2");
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_2_high2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_low1");
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_3_low1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_10_low2");
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_10_low2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_11_query");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_11_query);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
};
SouffleProgram *newInstance_tak(){return new Sf_tak;}
SymbolTable *getST_tak(SouffleProgram *p){return &reinterpret_cast<Sf_tak*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_tak: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_tak();
};
public:
factory_Sf_tak() : ProgramFactory("tak"){}
};
static factory_Sf_tak __factory_Sf_tak_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(tak.dl)",
R"(.)",
R"(.)",
false,
R"()",
1,
-1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_tak obj;
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
