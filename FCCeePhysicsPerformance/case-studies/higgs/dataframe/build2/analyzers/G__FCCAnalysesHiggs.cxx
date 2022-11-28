// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__FCCAnalysesHiggs
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
#include "dummyLoaderHiggs.h"
#include "APCHiggsTools.h"
#include "LLRHiggsTools.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace {
  void TriggerDictionaryInitialization_libFCCAnalysesHiggs_Impl() {
    static const char* headers[] = {
"dummyLoaderHiggs.h",
"APCHiggsTools.h",
"LLRHiggsTools.h",
nullptr
    };
    static const char* includePaths[] = {
"/cvmfs/sw.hsf.org/spackages5/root/6.26.00/x86_64-centos7-gcc11.2.0-opt/jx56q/include",
"/cvmfs/sw.hsf.org/spackages5/edm4hep/0.4.1/x86_64-centos7-gcc11.2.0-opt/22m2i/include",
"/cvmfs/sw.hsf.org/spackages5/podio/0.14.1/x86_64-centos7-gcc11.2.0-opt/apzae/include",
"/cvmfs/sw.hsf.org/spackages5/vdt/0.4.3/x86_64-centos7-gcc11.2.0-opt/vtti3/include",
"/cvmfs/sw.hsf.org/spackages5/fastjet/3.3.4/x86_64-centos7-gcc11.2.0-opt/lssz5/include",
"/afs/cern.ch/user/n/niharrin/work/public/MA/FCCeePhysicsPerformance/case-studies/higgs/dataframe/analyzers",
"/cvmfs/sw.hsf.org/spackages5/root/6.26.00/x86_64-centos7-gcc11.2.0-opt/jx56q/include/",
"/afs/cern.ch/work/n/niharrin/public/MA/FCCeePhysicsPerformance/case-studies/higgs/dataframe/build/analyzers/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libFCCAnalysesHiggs dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libFCCAnalysesHiggs dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "dummyLoaderHiggs.h"
#include "APCHiggsTools.h"
#include "LLRHiggsTools.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"dummyLoaderHiggs", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libFCCAnalysesHiggs",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libFCCAnalysesHiggs_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libFCCAnalysesHiggs_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libFCCAnalysesHiggs() {
  TriggerDictionaryInitialization_libFCCAnalysesHiggs_Impl();
}
