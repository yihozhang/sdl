
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
struct t_btree_4__0_1_2_3__1__15 {
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
void insertAll(t_btree_4__0_1_2_3__1__15& other) {
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
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
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

class Sf_cprog1 : public SouffleProgram {
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
;// -- Table: high
std::unique_ptr<t_btree_1__0__1> rel_1_high = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<0,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_1_high;
// -- Table: low
std::unique_ptr<t_btree_1__0__1> rel_2_low = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<1,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_2_low;
// -- Table: med
std::unique_ptr<t_btree_1__0__1> rel_3_med = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<2,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_3_med;
// -- Table: loop
std::unique_ptr<t_btree_4__0_1_2_3__1__15> rel_4_loop = std::make_unique<t_btree_4__0_1_2_3__1__15>();
souffle::RelationWrapper<3,t_btree_4__0_1_2_3__1__15,Tuple<RamDomain,4>,4,1> wrapper_rel_4_loop;
// -- Table: @delta_loop
std::unique_ptr<t_btree_4__0_1_2_3__1__15> rel_5_delta_loop = std::make_unique<t_btree_4__0_1_2_3__1__15>();
// -- Table: @new_loop
std::unique_ptr<t_btree_4__0_1_2_3__1__15> rel_6_new_loop = std::make_unique<t_btree_4__0_1_2_3__1__15>();
public:
Sf_cprog1() : 
wrapper_rel_1_high(*rel_1_high,symTable,"high",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"x"}}),

wrapper_rel_2_low(*rel_2_low,symTable,"low",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"x"}}),

wrapper_rel_3_med(*rel_3_med,symTable,"med",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"x"}}),

wrapper_rel_4_loop(*rel_4_loop,symTable,"loop",std::array<const char *,4>{{"i:number","i:number","i:number","i:number"}},std::array<const char *,4>{{"line","x","y","z"}}){
addRelation("high",&wrapper_rel_1_high,true,false);
addRelation("low",&wrapper_rel_2_low,true,false);
addRelation("med",&wrapper_rel_3_med,true,false);
addRelation("loop",&wrapper_rel_4_loop,false,true);
}
~Sf_cprog1() {
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./high.facts"},{"name","high"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_1_high);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./low.facts"},{"name","low"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_2_low);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./med.facts"},{"name","med"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_3_med);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
SignalHandler::instance()->setMsg(R"_(loop(0,l,m,h) :- 
   low(l),
   med(m),
   high(h).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cprog1/cprog1.dl [17:1-17:45])_");
if(!(rel_1_high->empty()) && !(rel_3_med->empty()) && !(rel_2_low->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_high_op_ctxt,rel_1_high->createContext());
CREATE_OP_CONTEXT(rel_2_low_op_ctxt,rel_2_low->createContext());
CREATE_OP_CONTEXT(rel_3_med_op_ctxt,rel_3_med->createContext());
CREATE_OP_CONTEXT(rel_4_loop_op_ctxt,rel_4_loop->createContext());
for(const auto& env0 : *rel_2_low) {
for(const auto& env1 : *rel_3_med) {
for(const auto& env2 : *rel_1_high) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(RamDomain(0)),static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0])}};
rel_4_loop->insert(tuple,READ_OP_CONTEXT(rel_4_loop_op_ctxt));
}
}
}
}
();}
rel_5_delta_loop->insertAll(*rel_4_loop);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(loop(1,x,y,z) :- 
   loop(0,x,y,z).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cprog1/cprog1.dl [19:1-19:38])_");
if(!(rel_5_delta_loop->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_4_loop_op_ctxt,rel_4_loop->createContext());
CREATE_OP_CONTEXT(rel_5_delta_loop_op_ctxt,rel_5_delta_loop->createContext());
CREATE_OP_CONTEXT(rel_6_new_loop_op_ctxt,rel_6_new_loop->createContext());
const Tuple<RamDomain,4> key{{RamDomain(0),0,0,0}};
auto range = rel_5_delta_loop->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_loop_op_ctxt));
for(const auto& env0 : range) {
if( !(rel_4_loop->contains(Tuple<RamDomain,4>{{RamDomain(1),env0[1],env0[2],env0[3]}},READ_OP_CONTEXT(rel_4_loop_op_ctxt)))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env0[3])}};
rel_6_new_loop->insert(tuple,READ_OP_CONTEXT(rel_6_new_loop_op_ctxt));
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(loop(1,(x+1),y,z) :- 
   loop(1,x,y,_),
   loop(0,_,_,z),
   x < y.
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cprog1/cprog1.dl [20:1-20:65])_");
if(!(rel_4_loop->empty()) && !(rel_5_delta_loop->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_4_loop_op_ctxt,rel_4_loop->createContext());
CREATE_OP_CONTEXT(rel_5_delta_loop_op_ctxt,rel_5_delta_loop->createContext());
CREATE_OP_CONTEXT(rel_6_new_loop_op_ctxt,rel_6_new_loop->createContext());
const Tuple<RamDomain,4> key{{RamDomain(1),0,0,0}};
auto range = rel_5_delta_loop->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_loop_op_ctxt));
for(const auto& env0 : range) {
if( ((env0[1]) < (env0[2]))) {
const Tuple<RamDomain,4> key{{RamDomain(0),0,0,0}};
auto range = rel_4_loop->equalRange_1(key,READ_OP_CONTEXT(rel_4_loop_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_4_loop->contains(Tuple<RamDomain,4>{{RamDomain(1),(env0[1]) + (RamDomain(1)),env0[2],env1[3]}},READ_OP_CONTEXT(rel_4_loop_op_ctxt))) && !(rel_5_delta_loop->contains(Tuple<RamDomain,4>{{RamDomain(0),env1[1],env1[2],env1[3]}},READ_OP_CONTEXT(rel_5_delta_loop_op_ctxt)))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((env0[1]) + (RamDomain(1))),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env1[3])}};
rel_6_new_loop->insert(tuple,READ_OP_CONTEXT(rel_6_new_loop_op_ctxt));
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(loop(1,(x+1),y,z) :- 
   loop(1,x,y,_),
   loop(0,_,_,z),
   x < y.
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cprog1/cprog1.dl [20:1-20:65])_");
if(!(rel_5_delta_loop->empty()) && !(rel_4_loop->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_4_loop_op_ctxt,rel_4_loop->createContext());
CREATE_OP_CONTEXT(rel_5_delta_loop_op_ctxt,rel_5_delta_loop->createContext());
CREATE_OP_CONTEXT(rel_6_new_loop_op_ctxt,rel_6_new_loop->createContext());
const Tuple<RamDomain,4> key{{RamDomain(1),0,0,0}};
auto range = rel_4_loop->equalRange_1(key,READ_OP_CONTEXT(rel_4_loop_op_ctxt));
for(const auto& env0 : range) {
if( ((env0[1]) < (env0[2]))) {
const Tuple<RamDomain,4> key{{RamDomain(0),0,0,0}};
auto range = rel_5_delta_loop->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_loop_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_4_loop->contains(Tuple<RamDomain,4>{{RamDomain(1),(env0[1]) + (RamDomain(1)),env0[2],env1[3]}},READ_OP_CONTEXT(rel_4_loop_op_ctxt)))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((env0[1]) + (RamDomain(1))),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env1[3])}};
rel_6_new_loop->insert(tuple,READ_OP_CONTEXT(rel_6_new_loop_op_ctxt));
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(loop(2,x,y,z) :- 
   loop(1,x,y,z),
   x >= y.
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cprog1/cprog1.dl [22:1-22:46])_");
if(!(rel_5_delta_loop->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_4_loop_op_ctxt,rel_4_loop->createContext());
CREATE_OP_CONTEXT(rel_5_delta_loop_op_ctxt,rel_5_delta_loop->createContext());
CREATE_OP_CONTEXT(rel_6_new_loop_op_ctxt,rel_6_new_loop->createContext());
const Tuple<RamDomain,4> key{{RamDomain(1),0,0,0}};
auto range = rel_5_delta_loop->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_loop_op_ctxt));
for(const auto& env0 : range) {
if( !(rel_4_loop->contains(Tuple<RamDomain,4>{{RamDomain(2),env0[1],env0[2],env0[3]}},READ_OP_CONTEXT(rel_4_loop_op_ctxt))) && ((env0[1]) >= (env0[2]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env0[3])}};
rel_6_new_loop->insert(tuple,READ_OP_CONTEXT(rel_6_new_loop_op_ctxt));
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(loop(2,x,(y+1),z) :- 
   loop(2,_,y,z),
   loop(1,x,_,_),
   y < z.
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cprog1/cprog1.dl [23:1-23:65])_");
if(!(rel_4_loop->empty()) && !(rel_5_delta_loop->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_4_loop_op_ctxt,rel_4_loop->createContext());
CREATE_OP_CONTEXT(rel_5_delta_loop_op_ctxt,rel_5_delta_loop->createContext());
CREATE_OP_CONTEXT(rel_6_new_loop_op_ctxt,rel_6_new_loop->createContext());
const Tuple<RamDomain,4> key{{RamDomain(2),0,0,0}};
auto range = rel_5_delta_loop->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_loop_op_ctxt));
for(const auto& env0 : range) {
if( ((env0[2]) < (env0[3]))) {
const Tuple<RamDomain,4> key{{RamDomain(1),0,0,0}};
auto range = rel_4_loop->equalRange_1(key,READ_OP_CONTEXT(rel_4_loop_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_4_loop->contains(Tuple<RamDomain,4>{{RamDomain(2),env1[1],(env0[2]) + (RamDomain(1)),env0[3]}},READ_OP_CONTEXT(rel_4_loop_op_ctxt))) && !(rel_5_delta_loop->contains(Tuple<RamDomain,4>{{RamDomain(1),env1[1],env1[2],env1[3]}},READ_OP_CONTEXT(rel_5_delta_loop_op_ctxt)))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>((env0[2]) + (RamDomain(1))),static_cast<RamDomain>(env0[3])}};
rel_6_new_loop->insert(tuple,READ_OP_CONTEXT(rel_6_new_loop_op_ctxt));
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(loop(2,x,(y+1),z) :- 
   loop(2,_,y,z),
   loop(1,x,_,_),
   y < z.
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cprog1/cprog1.dl [23:1-23:65])_");
if(!(rel_5_delta_loop->empty()) && !(rel_4_loop->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_4_loop_op_ctxt,rel_4_loop->createContext());
CREATE_OP_CONTEXT(rel_5_delta_loop_op_ctxt,rel_5_delta_loop->createContext());
CREATE_OP_CONTEXT(rel_6_new_loop_op_ctxt,rel_6_new_loop->createContext());
const Tuple<RamDomain,4> key{{RamDomain(2),0,0,0}};
auto range = rel_4_loop->equalRange_1(key,READ_OP_CONTEXT(rel_4_loop_op_ctxt));
for(const auto& env0 : range) {
if( ((env0[2]) < (env0[3]))) {
const Tuple<RamDomain,4> key{{RamDomain(1),0,0,0}};
auto range = rel_5_delta_loop->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_loop_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_4_loop->contains(Tuple<RamDomain,4>{{RamDomain(2),env1[1],(env0[2]) + (RamDomain(1)),env0[3]}},READ_OP_CONTEXT(rel_4_loop_op_ctxt)))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>((env0[2]) + (RamDomain(1))),static_cast<RamDomain>(env0[3])}};
rel_6_new_loop->insert(tuple,READ_OP_CONTEXT(rel_6_new_loop_op_ctxt));
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(loop(3,x,y,z) :- 
   loop(2,x,y,z),
   y >= z.
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/cprog1/cprog1.dl [25:1-25:46])_");
if(!(rel_5_delta_loop->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_4_loop_op_ctxt,rel_4_loop->createContext());
CREATE_OP_CONTEXT(rel_5_delta_loop_op_ctxt,rel_5_delta_loop->createContext());
CREATE_OP_CONTEXT(rel_6_new_loop_op_ctxt,rel_6_new_loop->createContext());
const Tuple<RamDomain,4> key{{RamDomain(2),0,0,0}};
auto range = rel_5_delta_loop->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_loop_op_ctxt));
for(const auto& env0 : range) {
if( !(rel_4_loop->contains(Tuple<RamDomain,4>{{RamDomain(3),env0[1],env0[2],env0[3]}},READ_OP_CONTEXT(rel_4_loop_op_ctxt))) && ((env0[2]) >= (env0[3]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(RamDomain(3)),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env0[3])}};
rel_6_new_loop->insert(tuple,READ_OP_CONTEXT(rel_6_new_loop_op_ctxt));
}
}
}
();}
if(rel_6_new_loop->empty()) break;
rel_4_loop->insertAll(*rel_6_new_loop);
std::swap(rel_5_delta_loop, rel_6_new_loop);
rel_6_new_loop->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_5_delta_loop->purge();
if (!isHintsProfilingEnabled()) rel_6_new_loop->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","line\tx\ty\tz"},{"filename","./loop.ans"},{"name","loop"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_4_loop);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_2_low->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_3_med->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_1_high->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_4_loop->purge();
}();
/* END STRATUM 3 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_high:\n";
rel_1_high->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_low:\n";
rel_2_low->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_med:\n";
rel_3_med->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_loop:\n";
rel_4_loop->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_delta_loop:\n";
rel_5_delta_loop->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_new_loop:\n";
rel_6_new_loop->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","line\tx\ty\tz"},{"filename","./loop.ans"},{"name","loop"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_4_loop);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./high.facts"},{"name","high"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_1_high);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./low.facts"},{"name","low"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_2_low);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./med.facts"},{"name","med"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->readAll(*rel_3_med);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_high");
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_1_high);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_low");
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_2_low);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_med");
IOSystem::getInstance().getWriter(std::vector<bool>({0}), symTable, ioDirectives, false, 1)->writeAll(*rel_3_med);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_loop");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_4_loop);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
};
SouffleProgram *newInstance_cprog1(){return new Sf_cprog1;}
SymbolTable *getST_cprog1(SouffleProgram *p){return &reinterpret_cast<Sf_cprog1*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_cprog1: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_cprog1();
};
public:
factory_Sf_cprog1() : ProgramFactory("cprog1"){}
};
static factory_Sf_cprog1 __factory_Sf_cprog1_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(cprog1.dl)",
R"(.)",
R"(.)",
false,
R"()",
1,
-1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_cprog1 obj;
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
