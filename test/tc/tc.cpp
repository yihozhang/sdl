
#include "souffle/CompiledSouffle.h"

extern "C" {
}

namespace souffle {
using namespace ram;
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

class Sf_tc : public SouffleProgram {
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
;// -- Table: base
std::unique_ptr<t_btree_2__0_1__1__3> rel_1_base = std::make_unique<t_btree_2__0_1__1__3>();
souffle::RelationWrapper<0,t_btree_2__0_1__1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_1_base;
// -- Table: tc
std::unique_ptr<t_btree_2__0_1__1__3> rel_2_tc = std::make_unique<t_btree_2__0_1__1__3>();
souffle::RelationWrapper<1,t_btree_2__0_1__1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_2_tc;
// -- Table: @delta_tc
std::unique_ptr<t_btree_2__0_1__1__3> rel_3_delta_tc = std::make_unique<t_btree_2__0_1__1__3>();
// -- Table: @new_tc
std::unique_ptr<t_btree_2__0_1__1__3> rel_4_new_tc = std::make_unique<t_btree_2__0_1__1__3>();
// -- Table: tcl
std::unique_ptr<t_btree_2__0_1__3> rel_5_tcl = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<2,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_5_tcl;
// -- Table: @delta_tcl
std::unique_ptr<t_btree_2__0_1__3> rel_6_delta_tcl = std::make_unique<t_btree_2__0_1__3>();
// -- Table: @new_tcl
std::unique_ptr<t_btree_2__0_1__3> rel_7_new_tcl = std::make_unique<t_btree_2__0_1__3>();
// -- Table: tcr
std::unique_ptr<t_btree_2__0_1__3> rel_8_tcr = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<3,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_8_tcr;
// -- Table: @delta_tcr
std::unique_ptr<t_btree_2__0_1__1__3> rel_9_delta_tcr = std::make_unique<t_btree_2__0_1__1__3>();
// -- Table: @new_tcr
std::unique_ptr<t_btree_2__0_1__1__3> rel_10_new_tcr = std::make_unique<t_btree_2__0_1__1__3>();
public:
Sf_tc() : 
wrapper_rel_1_base(*rel_1_base,symTable,"base",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"node1","node2"}}),

wrapper_rel_2_tc(*rel_2_tc,symTable,"tc",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"node1","node2"}}),

wrapper_rel_5_tcl(*rel_5_tcl,symTable,"tcl",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"node1","node2"}}),

wrapper_rel_8_tcr(*rel_8_tcr,symTable,"tcr",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"node1","node2"}}){
addRelation("base",&wrapper_rel_1_base,true,false);
addRelation("tc",&wrapper_rel_2_tc,false,true);
addRelation("tcl",&wrapper_rel_5_tcl,false,true);
addRelation("tcr",&wrapper_rel_8_tcr,false,true);
}
~Sf_tc() {
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./base.facts"},{"name","base"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_1_base);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
SignalHandler::instance()->setMsg(R"_(tc(X,Y) :- 
   base(X,Y).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tc/tc.dl [19:1-19:22])_");
if(!(rel_1_base->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_base_op_ctxt,rel_1_base->createContext());
CREATE_OP_CONTEXT(rel_2_tc_op_ctxt,rel_2_tc->createContext());
for(const auto& env0 : *rel_1_base) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}};
rel_2_tc->insert(tuple,READ_OP_CONTEXT(rel_2_tc_op_ctxt));
}
}
();}
rel_3_delta_tc->insertAll(*rel_2_tc);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(tc(X,Y) :- 
   tc(X,Z),
   tc(Z,Y).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tc/tc.dl [20:1-20:28])_");
if(!(rel_2_tc->empty()) && !(rel_3_delta_tc->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_2_tc_op_ctxt,rel_2_tc->createContext());
CREATE_OP_CONTEXT(rel_3_delta_tc_op_ctxt,rel_3_delta_tc->createContext());
CREATE_OP_CONTEXT(rel_4_new_tc_op_ctxt,rel_4_new_tc->createContext());
for(const auto& env0 : *rel_3_delta_tc) {
const Tuple<RamDomain,2> key{{env0[1],0}};
auto range = rel_2_tc->equalRange_1(key,READ_OP_CONTEXT(rel_2_tc_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_2_tc->contains(Tuple<RamDomain,2>{{env0[0],env1[1]}},READ_OP_CONTEXT(rel_2_tc_op_ctxt))) && !(rel_3_delta_tc->contains(Tuple<RamDomain,2>{{env0[1],env1[1]}},READ_OP_CONTEXT(rel_3_delta_tc_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}};
rel_4_new_tc->insert(tuple,READ_OP_CONTEXT(rel_4_new_tc_op_ctxt));
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(tc(X,Y) :- 
   tc(X,Z),
   tc(Z,Y).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tc/tc.dl [20:1-20:28])_");
if(!(rel_3_delta_tc->empty()) && !(rel_2_tc->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_2_tc_op_ctxt,rel_2_tc->createContext());
CREATE_OP_CONTEXT(rel_3_delta_tc_op_ctxt,rel_3_delta_tc->createContext());
CREATE_OP_CONTEXT(rel_4_new_tc_op_ctxt,rel_4_new_tc->createContext());
for(const auto& env0 : *rel_2_tc) {
const Tuple<RamDomain,2> key{{env0[1],0}};
auto range = rel_3_delta_tc->equalRange_1(key,READ_OP_CONTEXT(rel_3_delta_tc_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_2_tc->contains(Tuple<RamDomain,2>{{env0[0],env1[1]}},READ_OP_CONTEXT(rel_2_tc_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}};
rel_4_new_tc->insert(tuple,READ_OP_CONTEXT(rel_4_new_tc_op_ctxt));
}
}
}
}
();}
if(rel_4_new_tc->empty()) break;
rel_2_tc->insertAll(*rel_4_new_tc);
std::swap(rel_3_delta_tc, rel_4_new_tc);
rel_4_new_tc->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_3_delta_tc->purge();
if (!isHintsProfilingEnabled()) rel_4_new_tc->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","node1\tnode2"},{"filename","./tc.ans"},{"name","tc"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_2_tc);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_2_tc->purge();
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
SignalHandler::instance()->setMsg(R"_(tcl(X,Y) :- 
   base(X,Y).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tc/tc.dl [11:1-11:24])_");
if(!(rel_1_base->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_base_op_ctxt,rel_1_base->createContext());
CREATE_OP_CONTEXT(rel_5_tcl_op_ctxt,rel_5_tcl->createContext());
for(const auto& env0 : *rel_1_base) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}};
rel_5_tcl->insert(tuple,READ_OP_CONTEXT(rel_5_tcl_op_ctxt));
}
}
();}
rel_6_delta_tcl->insertAll(*rel_5_tcl);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(tcl(X,Y) :- 
   tcl(X,Z),
   base(Z,Y).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tc/tc.dl [12:1-12:33])_");
if(!(rel_1_base->empty()) && !(rel_6_delta_tcl->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_base_op_ctxt,rel_1_base->createContext());
CREATE_OP_CONTEXT(rel_6_delta_tcl_op_ctxt,rel_6_delta_tcl->createContext());
CREATE_OP_CONTEXT(rel_5_tcl_op_ctxt,rel_5_tcl->createContext());
CREATE_OP_CONTEXT(rel_7_new_tcl_op_ctxt,rel_7_new_tcl->createContext());
for(const auto& env0 : *rel_6_delta_tcl) {
const Tuple<RamDomain,2> key{{env0[1],0}};
auto range = rel_1_base->equalRange_1(key,READ_OP_CONTEXT(rel_1_base_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_5_tcl->contains(Tuple<RamDomain,2>{{env0[0],env1[1]}},READ_OP_CONTEXT(rel_5_tcl_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}};
rel_7_new_tcl->insert(tuple,READ_OP_CONTEXT(rel_7_new_tcl_op_ctxt));
}
}
}
}
();}
if(rel_7_new_tcl->empty()) break;
rel_5_tcl->insertAll(*rel_7_new_tcl);
std::swap(rel_6_delta_tcl, rel_7_new_tcl);
rel_7_new_tcl->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_6_delta_tcl->purge();
if (!isHintsProfilingEnabled()) rel_7_new_tcl->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","node1\tnode2"},{"filename","./tcl.ans"},{"name","tcl"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_5_tcl);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_5_tcl->purge();
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
SignalHandler::instance()->setMsg(R"_(tcr(X,Y) :- 
   base(X,Y).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tc/tc.dl [15:1-15:23])_");
if(!(rel_1_base->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_base_op_ctxt,rel_1_base->createContext());
CREATE_OP_CONTEXT(rel_8_tcr_op_ctxt,rel_8_tcr->createContext());
for(const auto& env0 : *rel_1_base) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}};
rel_8_tcr->insert(tuple,READ_OP_CONTEXT(rel_8_tcr_op_ctxt));
}
}
();}
rel_9_delta_tcr->insertAll(*rel_8_tcr);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(tcr(X,Y) :- 
   base(X,Z),
   tcr(Z,Y).
in file /Users/patrickyh/Documents/Academics/20wi/sdl/test/tc/tc.dl [16:1-16:33])_");
if(!(rel_9_delta_tcr->empty()) && !(rel_1_base->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_base_op_ctxt,rel_1_base->createContext());
CREATE_OP_CONTEXT(rel_8_tcr_op_ctxt,rel_8_tcr->createContext());
CREATE_OP_CONTEXT(rel_9_delta_tcr_op_ctxt,rel_9_delta_tcr->createContext());
CREATE_OP_CONTEXT(rel_10_new_tcr_op_ctxt,rel_10_new_tcr->createContext());
for(const auto& env0 : *rel_1_base) {
const Tuple<RamDomain,2> key{{env0[1],0}};
auto range = rel_9_delta_tcr->equalRange_1(key,READ_OP_CONTEXT(rel_9_delta_tcr_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_8_tcr->contains(Tuple<RamDomain,2>{{env0[0],env1[1]}},READ_OP_CONTEXT(rel_8_tcr_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}};
rel_10_new_tcr->insert(tuple,READ_OP_CONTEXT(rel_10_new_tcr_op_ctxt));
}
}
}
}
();}
if(rel_10_new_tcr->empty()) break;
rel_8_tcr->insertAll(*rel_10_new_tcr);
std::swap(rel_9_delta_tcr, rel_10_new_tcr);
rel_10_new_tcr->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_9_delta_tcr->purge();
if (!isHintsProfilingEnabled()) rel_10_new_tcr->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","node1\tnode2"},{"filename","./tcr.ans"},{"name","tcr"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_8_tcr);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_8_tcr->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_1_base->purge();
}();
/* END STRATUM 3 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_base:\n";
rel_1_base->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_tc:\n";
rel_2_tc->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_delta_tc:\n";
rel_3_delta_tc->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_new_tc:\n";
rel_4_new_tc->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_tcl:\n";
rel_5_tcl->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_delta_tcl:\n";
rel_6_delta_tcl->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_new_tcl:\n";
rel_7_new_tcl->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_tcr:\n";
rel_8_tcr->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_delta_tcr:\n";
rel_9_delta_tcr->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_new_tcr:\n";
rel_10_new_tcr->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","node1\tnode2"},{"filename","./tc.ans"},{"name","tc"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_2_tc);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","node1\tnode2"},{"filename","./tcl.ans"},{"name","tcl"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_5_tcl);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","node1\tnode2"},{"filename","./tcr.ans"},{"name","tcr"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_8_tcr);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./base.facts"},{"name","base"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_1_base);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_base");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_1_base);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_tc");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_2_tc);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_5_tcl");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_5_tcl);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_8_tcr");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_8_tcr);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
};
SouffleProgram *newInstance_tc(){return new Sf_tc;}
SymbolTable *getST_tc(SouffleProgram *p){return &reinterpret_cast<Sf_tc*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_tc: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_tc();
};
public:
factory_Sf_tc() : ProgramFactory("tc"){}
};
static factory_Sf_tc __factory_Sf_tc_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(tc.dl)",
R"(.)",
R"(.)",
false,
R"()",
1,
-1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_tc obj;
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
