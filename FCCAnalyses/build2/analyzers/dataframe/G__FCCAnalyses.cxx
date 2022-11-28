// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__FCCAnalyses
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "dummyLoader.h"
#include "MCParticle.h"
#include "ReconstructedParticle.h"
#include "ReconstructedParticle2Track.h"
#include "ReconstructedParticle2MC.h"
#include "Algorithms.h"
#include "JetClustering.h"
#include "JetClusteringUtils.h"
#include "JetTaggingUtils.h"
#include "ValenciaPlugin.h"
#include "VertexingUtils.h"
#include "VertexFitterSimple.h"
#include "VertexFinderActs.h"
#include "VertexFitterActs.h"
#include "awkwardtest.h"
#include "myUtils.h"
#include "myFinalSel.h"
#include "CaloNtupleizer.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary();
   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEintgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEintgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p);
   static void destruct_vectorlEvectorlEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<int> >*)
   {
      vector<vector<int> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<int> >", -2, "vector", 389,
                  typeid(vector<vector<int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEintgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<int> >) );
      instance.SetNew(&new_vectorlEvectorlEintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEintgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<int> > >()));

      ::ROOT::AddClassAlternate("vector<vector<int> >","std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<int> >*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<int> >*)nullptr)->GetClass();
      vectorlEvectorlEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<int> > : new vector<vector<int> >;
   }
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<int> >[nElements] : new vector<vector<int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEintgRsPgR(void *p) {
      delete ((vector<vector<int> >*)p);
   }
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p) {
      delete [] ((vector<vector<int> >*)p);
   }
   static void destruct_vectorlEvectorlEintgRsPgR(void *p) {
      typedef vector<vector<int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<int> >

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = nullptr);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 389,
                  typeid(vector<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));

      ::ROOT::AddClassAlternate("vector<string>","std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<string>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<string>*)nullptr)->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete ((vector<string>*)p);
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] ((vector<string>*)p);
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = nullptr);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 389,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      ::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<int>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)nullptr)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlETLorentzVectorgR_Dictionary();
   static void vectorlETLorentzVectorgR_TClassManip(TClass*);
   static void *new_vectorlETLorentzVectorgR(void *p = nullptr);
   static void *newArray_vectorlETLorentzVectorgR(Long_t size, void *p);
   static void delete_vectorlETLorentzVectorgR(void *p);
   static void deleteArray_vectorlETLorentzVectorgR(void *p);
   static void destruct_vectorlETLorentzVectorgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TLorentzVector>*)
   {
      vector<TLorentzVector> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TLorentzVector>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TLorentzVector>", -2, "vector", 389,
                  typeid(vector<TLorentzVector>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETLorentzVectorgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TLorentzVector>) );
      instance.SetNew(&new_vectorlETLorentzVectorgR);
      instance.SetNewArray(&newArray_vectorlETLorentzVectorgR);
      instance.SetDelete(&delete_vectorlETLorentzVectorgR);
      instance.SetDeleteArray(&deleteArray_vectorlETLorentzVectorgR);
      instance.SetDestructor(&destruct_vectorlETLorentzVectorgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TLorentzVector> >()));

      ::ROOT::AddClassAlternate("vector<TLorentzVector>","std::vector<TLorentzVector, std::allocator<TLorentzVector> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TLorentzVector>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETLorentzVectorgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TLorentzVector>*)nullptr)->GetClass();
      vectorlETLorentzVectorgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETLorentzVectorgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETLorentzVectorgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TLorentzVector> : new vector<TLorentzVector>;
   }
   static void *newArray_vectorlETLorentzVectorgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TLorentzVector>[nElements] : new vector<TLorentzVector>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETLorentzVectorgR(void *p) {
      delete ((vector<TLorentzVector>*)p);
   }
   static void deleteArray_vectorlETLorentzVectorgR(void *p) {
      delete [] ((vector<TLorentzVector>*)p);
   }
   static void destruct_vectorlETLorentzVectorgR(void *p) {
      typedef vector<TLorentzVector> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TLorentzVector>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::VertexData>*)
   {
      ROOT::VecOps::RVec<edm4hep::VertexData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::VertexData>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::VertexData>", -2, "ROOT/RVec.hxx", 1422,
                  typeid(ROOT::VecOps::RVec<edm4hep::VertexData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::VertexData>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::VertexData> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::VertexData>*)
   {
      return GenerateInitInstanceLocal((ROOT::VecOps::RVec<edm4hep::VertexData>*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ROOT::VecOps::RVec<edm4hep::VertexData>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ROOT::VecOps::RVec<edm4hep::VertexData>*)nullptr)->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::VertexData> : new ROOT::VecOps::RVec<edm4hep::VertexData>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::VertexData>[nElements] : new ROOT::VecOps::RVec<edm4hep::VertexData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p) {
      delete ((ROOT::VecOps::RVec<edm4hep::VertexData>*)p);
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p) {
      delete [] ((ROOT::VecOps::RVec<edm4hep::VertexData>*)p);
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::VertexData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::VertexData>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::Vector3d>*)
   {
      ROOT::VecOps::RVec<edm4hep::Vector3d> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::Vector3d>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::Vector3d>", -2, "ROOT/RVec.hxx", 1422,
                  typeid(ROOT::VecOps::RVec<edm4hep::Vector3d>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::Vector3d>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::Vector3d> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::Vector3d>*)
   {
      return GenerateInitInstanceLocal((ROOT::VecOps::RVec<edm4hep::Vector3d>*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ROOT::VecOps::RVec<edm4hep::Vector3d>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ROOT::VecOps::RVec<edm4hep::Vector3d>*)nullptr)->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::Vector3d> : new ROOT::VecOps::RVec<edm4hep::Vector3d>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::Vector3d>[nElements] : new ROOT::VecOps::RVec<edm4hep::Vector3d>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p) {
      delete ((ROOT::VecOps::RVec<edm4hep::Vector3d>*)p);
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p) {
      delete [] ((ROOT::VecOps::RVec<edm4hep::Vector3d>*)p);
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::Vector3d> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::Vector3d>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::TrackState>*)
   {
      ROOT::VecOps::RVec<edm4hep::TrackState> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::TrackState>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::TrackState>", -2, "ROOT/RVec.hxx", 1422,
                  typeid(ROOT::VecOps::RVec<edm4hep::TrackState>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::TrackState>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::TrackState> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::TrackState>*)
   {
      return GenerateInitInstanceLocal((ROOT::VecOps::RVec<edm4hep::TrackState>*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ROOT::VecOps::RVec<edm4hep::TrackState>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ROOT::VecOps::RVec<edm4hep::TrackState>*)nullptr)->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::TrackState> : new ROOT::VecOps::RVec<edm4hep::TrackState>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::TrackState>[nElements] : new ROOT::VecOps::RVec<edm4hep::TrackState>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p) {
      delete ((ROOT::VecOps::RVec<edm4hep::TrackState>*)p);
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p) {
      delete [] ((ROOT::VecOps::RVec<edm4hep::TrackState>*)p);
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::TrackState> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::TrackState>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*)
   {
      ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>", -2, "ROOT/RVec.hxx", 1422,
                  typeid(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*)
   {
      return GenerateInitInstanceLocal((ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*)nullptr)->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> : new ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>[nElements] : new ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p) {
      delete ((ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*)p);
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p) {
      delete [] ((ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*)p);
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::MCParticleData>*)
   {
      ROOT::VecOps::RVec<edm4hep::MCParticleData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::MCParticleData>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::MCParticleData>", -2, "ROOT/RVec.hxx", 1422,
                  typeid(ROOT::VecOps::RVec<edm4hep::MCParticleData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::MCParticleData>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::MCParticleData> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::MCParticleData>*)
   {
      return GenerateInitInstanceLocal((ROOT::VecOps::RVec<edm4hep::MCParticleData>*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ROOT::VecOps::RVec<edm4hep::MCParticleData>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ROOT::VecOps::RVec<edm4hep::MCParticleData>*)nullptr)->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::MCParticleData> : new ROOT::VecOps::RVec<edm4hep::MCParticleData>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::MCParticleData>[nElements] : new ROOT::VecOps::RVec<edm4hep::MCParticleData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p) {
      delete ((ROOT::VecOps::RVec<edm4hep::MCParticleData>*)p);
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p) {
      delete [] ((ROOT::VecOps::RVec<edm4hep::MCParticleData>*)p);
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::MCParticleData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::MCParticleData>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclETVector3gR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclETVector3gR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclETVector3gR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<TVector3>*)
   {
      ROOT::VecOps::RVec<TVector3> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<TVector3>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<TVector3>", -2, "ROOT/RVec.hxx", 1422,
                  typeid(ROOT::VecOps::RVec<TVector3>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclETVector3gR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<TVector3>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclETVector3gR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclETVector3gR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclETVector3gR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclETVector3gR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclETVector3gR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<TVector3> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<TVector3>*)
   {
      return GenerateInitInstanceLocal((ROOT::VecOps::RVec<TVector3>*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ROOT::VecOps::RVec<TVector3>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclETVector3gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ROOT::VecOps::RVec<TVector3>*)nullptr)->GetClass();
      ROOTcLcLVecOpscLcLRVeclETVector3gR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclETVector3gR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<TVector3> : new ROOT::VecOps::RVec<TVector3>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclETVector3gR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<TVector3>[nElements] : new ROOT::VecOps::RVec<TVector3>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p) {
      delete ((ROOT::VecOps::RVec<TVector3>*)p);
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p) {
      delete [] ((ROOT::VecOps::RVec<TVector3>*)p);
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p) {
      typedef ROOT::VecOps::RVec<TVector3> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<TVector3>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<TLorentzVector>*)
   {
      ROOT::VecOps::RVec<TLorentzVector> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<TLorentzVector>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<TLorentzVector>", -2, "ROOT/RVec.hxx", 1422,
                  typeid(ROOT::VecOps::RVec<TLorentzVector>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<TLorentzVector>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<TLorentzVector> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<TLorentzVector>*)
   {
      return GenerateInitInstanceLocal((ROOT::VecOps::RVec<TLorentzVector>*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ROOT::VecOps::RVec<TLorentzVector>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ROOT::VecOps::RVec<TLorentzVector>*)nullptr)->GetClass();
      ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<TLorentzVector> : new ROOT::VecOps::RVec<TLorentzVector>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<TLorentzVector>[nElements] : new ROOT::VecOps::RVec<TLorentzVector>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p) {
      delete ((ROOT::VecOps::RVec<TLorentzVector>*)p);
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p) {
      delete [] ((ROOT::VecOps::RVec<TLorentzVector>*)p);
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p) {
      typedef ROOT::VecOps::RVec<TLorentzVector> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<TLorentzVector>

namespace {
  void TriggerDictionaryInitialization_libFCCAnalyses_Impl() {
    static const char* headers[] = {
"dummyLoader.h",
"MCParticle.h",
"ReconstructedParticle.h",
"ReconstructedParticle2Track.h",
"ReconstructedParticle2MC.h",
"Algorithms.h",
"JetClustering.h",
"JetClusteringUtils.h",
"JetTaggingUtils.h",
"ValenciaPlugin.h",
"VertexingUtils.h",
"VertexFitterSimple.h",
"VertexFinderActs.h",
"VertexFitterActs.h",
"awkwardtest.h",
"myUtils.h",
"myFinalSel.h",
"CaloNtupleizer.h",
nullptr
    };
    static const char* includePaths[] = {
"/cvmfs/sw.hsf.org/spackages5/py-awkward/1.4.0/x86_64-centos7-gcc11.2.0-opt/ee337/lib/python3.9/site-packages/awkward/include",
"/cvmfs/sw.hsf.org/spackages5/root/6.26.00/x86_64-centos7-gcc11.2.0-opt/jx56q/include",
"/cvmfs/sw.hsf.org/spackages5/clhep/2.4.5.1/x86_64-centos7-gcc11.2.0-opt/jbvut/lib/CLHEP-2.4.5.1/../../include",
"/cvmfs/sw.hsf.org/spackages5/edm4hep/0.4.1/x86_64-centos7-gcc11.2.0-opt/22m2i/include",
"/cvmfs/sw.hsf.org/spackages5/podio/0.14.1/x86_64-centos7-gcc11.2.0-opt/apzae/include",
"/cvmfs/sw.hsf.org/spackages5/fastjet/3.3.4/x86_64-centos7-gcc11.2.0-opt/lssz5/include",
"/cvmfs/sw.hsf.org/spackages5/vdt/0.4.3/x86_64-centos7-gcc11.2.0-opt/vtti3/include",
"/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe",
"/cvmfs/sw.hsf.org/spackages5/root/6.26.00/x86_64-centos7-gcc11.2.0-opt/jx56q/include/",
"/afs/cern.ch/work/n/niharrin/public/MA/FCCAnalyses/build/analyzers/dataframe/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libFCCAnalyses dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace std{template <class _CharT> struct __attribute__((annotate("$clingAutoload$bits/char_traits.h")))  __attribute__((annotate("$clingAutoload$string")))  char_traits;
}
namespace std{template <typename > class __attribute__((annotate("$clingAutoload$bits/memoryfwd.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$TLorentzVector.h")))  __attribute__((annotate("$clingAutoload$MCParticle.h")))  TLorentzVector;
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/MCParticleData.h")))  __attribute__((annotate("$clingAutoload$MCParticle.h")))  MCParticleData;}
namespace ROOT{namespace VecOps{template <typename T> class __attribute__((annotate(R"ATTRDUMP(__cling__ptrcheck(off))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$ROOT/RVec.hxx")))  __attribute__((annotate("$clingAutoload$MCParticle.h")))  RVec;
}}
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/Vector3d.h")))  __attribute__((annotate("$clingAutoload$MCParticle.h")))  Vector3d;}
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/ReconstructedParticleData.h")))  __attribute__((annotate("$clingAutoload$ReconstructedParticle.h")))  ReconstructedParticleData;}
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/TrackState.h")))  __attribute__((annotate("$clingAutoload$ReconstructedParticle2Track.h")))  TrackState;}
class __attribute__((annotate("$clingAutoload$TVector3.h")))  __attribute__((annotate("$clingAutoload$MCParticle.h")))  TVector3;
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/VertexData.h")))  __attribute__((annotate("$clingAutoload$VertexingUtils.h")))  VertexData;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libFCCAnalyses dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "dummyLoader.h"
#include "MCParticle.h"
#include "ReconstructedParticle.h"
#include "ReconstructedParticle2Track.h"
#include "ReconstructedParticle2MC.h"
#include "Algorithms.h"
#include "JetClustering.h"
#include "JetClusteringUtils.h"
#include "JetTaggingUtils.h"
#include "ValenciaPlugin.h"
#include "VertexingUtils.h"
#include "VertexFitterSimple.h"
#include "VertexFinderActs.h"
#include "VertexFitterActs.h"
#include "awkwardtest.h"
#include "myUtils.h"
#include "myFinalSel.h"
#include "CaloNtupleizer.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"ROOT::VecOps::RVec<TLorentzVector>", payloadCode, "@",
"ROOT::VecOps::RVec<TVector3>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::MCParticleData>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::TrackState>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::Vector3d>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::VertexData>", payloadCode, "@",
"dummyLoader", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libFCCAnalyses",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libFCCAnalyses_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libFCCAnalyses_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libFCCAnalyses() {
  TriggerDictionaryInitialization_libFCCAnalyses_Impl();
}
