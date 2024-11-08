// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIhomedIemmadIDocumentsdITILGITHUBdIbuilddIdictdINextSimEvent
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
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
#include "/home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_nDetTraceStructure(void *p = nullptr);
   static void *newArray_nDetTraceStructure(Long_t size, void *p);
   static void delete_nDetTraceStructure(void *p);
   static void deleteArray_nDetTraceStructure(void *p);
   static void destruct_nDetTraceStructure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::nDetTraceStructure*)
   {
      ::nDetTraceStructure *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::nDetTraceStructure >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("nDetTraceStructure", ::nDetTraceStructure::Class_Version(), "include/nDetStructures.hpp", 28,
                  typeid(::nDetTraceStructure), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::nDetTraceStructure::Dictionary, isa_proxy, 4,
                  sizeof(::nDetTraceStructure) );
      instance.SetNew(&new_nDetTraceStructure);
      instance.SetNewArray(&newArray_nDetTraceStructure);
      instance.SetDelete(&delete_nDetTraceStructure);
      instance.SetDeleteArray(&deleteArray_nDetTraceStructure);
      instance.SetDestructor(&destruct_nDetTraceStructure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::nDetTraceStructure*)
   {
      return GenerateInitInstanceLocal(static_cast<::nDetTraceStructure*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::nDetTraceStructure*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_nDetEventStructure(void *p = nullptr);
   static void *newArray_nDetEventStructure(Long_t size, void *p);
   static void delete_nDetEventStructure(void *p);
   static void deleteArray_nDetEventStructure(void *p);
   static void destruct_nDetEventStructure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::nDetEventStructure*)
   {
      ::nDetEventStructure *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::nDetEventStructure >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("nDetEventStructure", ::nDetEventStructure::Class_Version(), "include/nDetStructures.hpp", 70,
                  typeid(::nDetEventStructure), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::nDetEventStructure::Dictionary, isa_proxy, 4,
                  sizeof(::nDetEventStructure) );
      instance.SetNew(&new_nDetEventStructure);
      instance.SetNewArray(&newArray_nDetEventStructure);
      instance.SetDelete(&delete_nDetEventStructure);
      instance.SetDeleteArray(&deleteArray_nDetEventStructure);
      instance.SetDestructor(&destruct_nDetEventStructure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::nDetEventStructure*)
   {
      return GenerateInitInstanceLocal(static_cast<::nDetEventStructure*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::nDetEventStructure*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_nDetOutputStructure(void *p = nullptr);
   static void *newArray_nDetOutputStructure(Long_t size, void *p);
   static void delete_nDetOutputStructure(void *p);
   static void deleteArray_nDetOutputStructure(void *p);
   static void destruct_nDetOutputStructure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::nDetOutputStructure*)
   {
      ::nDetOutputStructure *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::nDetOutputStructure >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("nDetOutputStructure", ::nDetOutputStructure::Class_Version(), "include/nDetStructures.hpp", 122,
                  typeid(::nDetOutputStructure), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::nDetOutputStructure::Dictionary, isa_proxy, 4,
                  sizeof(::nDetOutputStructure) );
      instance.SetNew(&new_nDetOutputStructure);
      instance.SetNewArray(&newArray_nDetOutputStructure);
      instance.SetDelete(&delete_nDetOutputStructure);
      instance.SetDeleteArray(&deleteArray_nDetOutputStructure);
      instance.SetDestructor(&destruct_nDetOutputStructure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::nDetOutputStructure*)
   {
      return GenerateInitInstanceLocal(static_cast<::nDetOutputStructure*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::nDetOutputStructure*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_nDetImplantOutputStructure(void *p = nullptr);
   static void *newArray_nDetImplantOutputStructure(Long_t size, void *p);
   static void delete_nDetImplantOutputStructure(void *p);
   static void deleteArray_nDetImplantOutputStructure(void *p);
   static void destruct_nDetImplantOutputStructure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::nDetImplantOutputStructure*)
   {
      ::nDetImplantOutputStructure *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::nDetImplantOutputStructure >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("nDetImplantOutputStructure", ::nDetImplantOutputStructure::Class_Version(), "include/nDetStructures.hpp", 187,
                  typeid(::nDetImplantOutputStructure), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::nDetImplantOutputStructure::Dictionary, isa_proxy, 4,
                  sizeof(::nDetImplantOutputStructure) );
      instance.SetNew(&new_nDetImplantOutputStructure);
      instance.SetNewArray(&newArray_nDetImplantOutputStructure);
      instance.SetDelete(&delete_nDetImplantOutputStructure);
      instance.SetDeleteArray(&deleteArray_nDetImplantOutputStructure);
      instance.SetDestructor(&destruct_nDetImplantOutputStructure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::nDetImplantOutputStructure*)
   {
      return GenerateInitInstanceLocal(static_cast<::nDetImplantOutputStructure*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::nDetImplantOutputStructure*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_nDetDebugStructure(void *p = nullptr);
   static void *newArray_nDetDebugStructure(Long_t size, void *p);
   static void delete_nDetDebugStructure(void *p);
   static void deleteArray_nDetDebugStructure(void *p);
   static void destruct_nDetDebugStructure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::nDetDebugStructure*)
   {
      ::nDetDebugStructure *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::nDetDebugStructure >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("nDetDebugStructure", ::nDetDebugStructure::Class_Version(), "include/nDetStructures.hpp", 250,
                  typeid(::nDetDebugStructure), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::nDetDebugStructure::Dictionary, isa_proxy, 4,
                  sizeof(::nDetDebugStructure) );
      instance.SetNew(&new_nDetDebugStructure);
      instance.SetNewArray(&newArray_nDetDebugStructure);
      instance.SetDelete(&delete_nDetDebugStructure);
      instance.SetDeleteArray(&deleteArray_nDetDebugStructure);
      instance.SetDestructor(&destruct_nDetDebugStructure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::nDetDebugStructure*)
   {
      return GenerateInitInstanceLocal(static_cast<::nDetDebugStructure*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::nDetDebugStructure*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_nDetMultiOutputStructure(void *p = nullptr);
   static void *newArray_nDetMultiOutputStructure(Long_t size, void *p);
   static void delete_nDetMultiOutputStructure(void *p);
   static void deleteArray_nDetMultiOutputStructure(void *p);
   static void destruct_nDetMultiOutputStructure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::nDetMultiOutputStructure*)
   {
      ::nDetMultiOutputStructure *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::nDetMultiOutputStructure >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("nDetMultiOutputStructure", ::nDetMultiOutputStructure::Class_Version(), "include/nDetStructures.hpp", 355,
                  typeid(::nDetMultiOutputStructure), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::nDetMultiOutputStructure::Dictionary, isa_proxy, 4,
                  sizeof(::nDetMultiOutputStructure) );
      instance.SetNew(&new_nDetMultiOutputStructure);
      instance.SetNewArray(&newArray_nDetMultiOutputStructure);
      instance.SetDelete(&delete_nDetMultiOutputStructure);
      instance.SetDeleteArray(&deleteArray_nDetMultiOutputStructure);
      instance.SetDestructor(&destruct_nDetMultiOutputStructure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::nDetMultiOutputStructure*)
   {
      return GenerateInitInstanceLocal(static_cast<::nDetMultiOutputStructure*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::nDetMultiOutputStructure*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr nDetTraceStructure::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *nDetTraceStructure::Class_Name()
{
   return "nDetTraceStructure";
}

//______________________________________________________________________________
const char *nDetTraceStructure::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetTraceStructure*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int nDetTraceStructure::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetTraceStructure*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *nDetTraceStructure::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetTraceStructure*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *nDetTraceStructure::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetTraceStructure*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr nDetEventStructure::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *nDetEventStructure::Class_Name()
{
   return "nDetEventStructure";
}

//______________________________________________________________________________
const char *nDetEventStructure::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetEventStructure*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int nDetEventStructure::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetEventStructure*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *nDetEventStructure::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetEventStructure*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *nDetEventStructure::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetEventStructure*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr nDetOutputStructure::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *nDetOutputStructure::Class_Name()
{
   return "nDetOutputStructure";
}

//______________________________________________________________________________
const char *nDetOutputStructure::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetOutputStructure*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int nDetOutputStructure::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetOutputStructure*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *nDetOutputStructure::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetOutputStructure*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *nDetOutputStructure::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetOutputStructure*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr nDetImplantOutputStructure::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *nDetImplantOutputStructure::Class_Name()
{
   return "nDetImplantOutputStructure";
}

//______________________________________________________________________________
const char *nDetImplantOutputStructure::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetImplantOutputStructure*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int nDetImplantOutputStructure::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetImplantOutputStructure*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *nDetImplantOutputStructure::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetImplantOutputStructure*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *nDetImplantOutputStructure::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetImplantOutputStructure*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr nDetDebugStructure::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *nDetDebugStructure::Class_Name()
{
   return "nDetDebugStructure";
}

//______________________________________________________________________________
const char *nDetDebugStructure::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetDebugStructure*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int nDetDebugStructure::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetDebugStructure*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *nDetDebugStructure::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetDebugStructure*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *nDetDebugStructure::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetDebugStructure*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr nDetMultiOutputStructure::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *nDetMultiOutputStructure::Class_Name()
{
   return "nDetMultiOutputStructure";
}

//______________________________________________________________________________
const char *nDetMultiOutputStructure::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetMultiOutputStructure*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int nDetMultiOutputStructure::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::nDetMultiOutputStructure*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *nDetMultiOutputStructure::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetMultiOutputStructure*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *nDetMultiOutputStructure::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::nDetMultiOutputStructure*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void nDetTraceStructure::Streamer(TBuffer &R__b)
{
   // Stream an object of class nDetTraceStructure.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(nDetTraceStructure::Class(),this);
   } else {
      R__b.WriteClassBuffer(nDetTraceStructure::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_nDetTraceStructure(void *p) {
      return  p ? new(p) ::nDetTraceStructure : new ::nDetTraceStructure;
   }
   static void *newArray_nDetTraceStructure(Long_t nElements, void *p) {
      return p ? new(p) ::nDetTraceStructure[nElements] : new ::nDetTraceStructure[nElements];
   }
   // Wrapper around operator delete
   static void delete_nDetTraceStructure(void *p) {
      delete (static_cast<::nDetTraceStructure*>(p));
   }
   static void deleteArray_nDetTraceStructure(void *p) {
      delete [] (static_cast<::nDetTraceStructure*>(p));
   }
   static void destruct_nDetTraceStructure(void *p) {
      typedef ::nDetTraceStructure current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::nDetTraceStructure

//______________________________________________________________________________
void nDetEventStructure::Streamer(TBuffer &R__b)
{
   // Stream an object of class nDetEventStructure.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(nDetEventStructure::Class(),this);
   } else {
      R__b.WriteClassBuffer(nDetEventStructure::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_nDetEventStructure(void *p) {
      return  p ? new(p) ::nDetEventStructure : new ::nDetEventStructure;
   }
   static void *newArray_nDetEventStructure(Long_t nElements, void *p) {
      return p ? new(p) ::nDetEventStructure[nElements] : new ::nDetEventStructure[nElements];
   }
   // Wrapper around operator delete
   static void delete_nDetEventStructure(void *p) {
      delete (static_cast<::nDetEventStructure*>(p));
   }
   static void deleteArray_nDetEventStructure(void *p) {
      delete [] (static_cast<::nDetEventStructure*>(p));
   }
   static void destruct_nDetEventStructure(void *p) {
      typedef ::nDetEventStructure current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::nDetEventStructure

//______________________________________________________________________________
void nDetOutputStructure::Streamer(TBuffer &R__b)
{
   // Stream an object of class nDetOutputStructure.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(nDetOutputStructure::Class(),this);
   } else {
      R__b.WriteClassBuffer(nDetOutputStructure::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_nDetOutputStructure(void *p) {
      return  p ? new(p) ::nDetOutputStructure : new ::nDetOutputStructure;
   }
   static void *newArray_nDetOutputStructure(Long_t nElements, void *p) {
      return p ? new(p) ::nDetOutputStructure[nElements] : new ::nDetOutputStructure[nElements];
   }
   // Wrapper around operator delete
   static void delete_nDetOutputStructure(void *p) {
      delete (static_cast<::nDetOutputStructure*>(p));
   }
   static void deleteArray_nDetOutputStructure(void *p) {
      delete [] (static_cast<::nDetOutputStructure*>(p));
   }
   static void destruct_nDetOutputStructure(void *p) {
      typedef ::nDetOutputStructure current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::nDetOutputStructure

//______________________________________________________________________________
void nDetImplantOutputStructure::Streamer(TBuffer &R__b)
{
   // Stream an object of class nDetImplantOutputStructure.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(nDetImplantOutputStructure::Class(),this);
   } else {
      R__b.WriteClassBuffer(nDetImplantOutputStructure::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_nDetImplantOutputStructure(void *p) {
      return  p ? new(p) ::nDetImplantOutputStructure : new ::nDetImplantOutputStructure;
   }
   static void *newArray_nDetImplantOutputStructure(Long_t nElements, void *p) {
      return p ? new(p) ::nDetImplantOutputStructure[nElements] : new ::nDetImplantOutputStructure[nElements];
   }
   // Wrapper around operator delete
   static void delete_nDetImplantOutputStructure(void *p) {
      delete (static_cast<::nDetImplantOutputStructure*>(p));
   }
   static void deleteArray_nDetImplantOutputStructure(void *p) {
      delete [] (static_cast<::nDetImplantOutputStructure*>(p));
   }
   static void destruct_nDetImplantOutputStructure(void *p) {
      typedef ::nDetImplantOutputStructure current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::nDetImplantOutputStructure

//______________________________________________________________________________
void nDetDebugStructure::Streamer(TBuffer &R__b)
{
   // Stream an object of class nDetDebugStructure.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(nDetDebugStructure::Class(),this);
   } else {
      R__b.WriteClassBuffer(nDetDebugStructure::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_nDetDebugStructure(void *p) {
      return  p ? new(p) ::nDetDebugStructure : new ::nDetDebugStructure;
   }
   static void *newArray_nDetDebugStructure(Long_t nElements, void *p) {
      return p ? new(p) ::nDetDebugStructure[nElements] : new ::nDetDebugStructure[nElements];
   }
   // Wrapper around operator delete
   static void delete_nDetDebugStructure(void *p) {
      delete (static_cast<::nDetDebugStructure*>(p));
   }
   static void deleteArray_nDetDebugStructure(void *p) {
      delete [] (static_cast<::nDetDebugStructure*>(p));
   }
   static void destruct_nDetDebugStructure(void *p) {
      typedef ::nDetDebugStructure current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::nDetDebugStructure

//______________________________________________________________________________
void nDetMultiOutputStructure::Streamer(TBuffer &R__b)
{
   // Stream an object of class nDetMultiOutputStructure.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(nDetMultiOutputStructure::Class(),this);
   } else {
      R__b.WriteClassBuffer(nDetMultiOutputStructure::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_nDetMultiOutputStructure(void *p) {
      return  p ? new(p) ::nDetMultiOutputStructure : new ::nDetMultiOutputStructure;
   }
   static void *newArray_nDetMultiOutputStructure(Long_t nElements, void *p) {
      return p ? new(p) ::nDetMultiOutputStructure[nElements] : new ::nDetMultiOutputStructure[nElements];
   }
   // Wrapper around operator delete
   static void delete_nDetMultiOutputStructure(void *p) {
      delete (static_cast<::nDetMultiOutputStructure*>(p));
   }
   static void deleteArray_nDetMultiOutputStructure(void *p) {
      delete [] (static_cast<::nDetMultiOutputStructure*>(p));
   }
   static void destruct_nDetMultiOutputStructure(void *p) {
      typedef ::nDetMultiOutputStructure current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::nDetMultiOutputStructure

namespace ROOT {
   static TClass *vectorlEunsignedsPshortgR_Dictionary();
   static void vectorlEunsignedsPshortgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPshortgR(void *p = nullptr);
   static void *newArray_vectorlEunsignedsPshortgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPshortgR(void *p);
   static void deleteArray_vectorlEunsignedsPshortgR(void *p);
   static void destruct_vectorlEunsignedsPshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned short>*)
   {
      vector<unsigned short> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned short>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned short>", -2, "vector", 389,
                  typeid(vector<unsigned short>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPshortgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned short>) );
      instance.SetNew(&new_vectorlEunsignedsPshortgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPshortgR);
      instance.SetDelete(&delete_vectorlEunsignedsPshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPshortgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned short> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<unsigned short>","std::vector<unsigned short, std::allocator<unsigned short> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<unsigned short>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<unsigned short>*>(nullptr))->GetClass();
      vectorlEunsignedsPshortgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPshortgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned short> : new vector<unsigned short>;
   }
   static void *newArray_vectorlEunsignedsPshortgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned short>[nElements] : new vector<unsigned short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPshortgR(void *p) {
      delete (static_cast<vector<unsigned short>*>(p));
   }
   static void deleteArray_vectorlEunsignedsPshortgR(void *p) {
      delete [] (static_cast<vector<unsigned short>*>(p));
   }
   static void destruct_vectorlEunsignedsPshortgR(void *p) {
      typedef vector<unsigned short> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned short>

namespace ROOT {
   static TClass *vectorlEunsignedsPintgR_Dictionary();
   static void vectorlEunsignedsPintgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPintgR(void *p = nullptr);
   static void *newArray_vectorlEunsignedsPintgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPintgR(void *p);
   static void deleteArray_vectorlEunsignedsPintgR(void *p);
   static void destruct_vectorlEunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned int>*)
   {
      vector<unsigned int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned int>", -2, "vector", 389,
                  typeid(vector<unsigned int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned int>) );
      instance.SetNew(&new_vectorlEunsignedsPintgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPintgR);
      instance.SetDelete(&delete_vectorlEunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPintgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned int> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<unsigned int>","std::vector<unsigned int, std::allocator<unsigned int> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<unsigned int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<unsigned int>*>(nullptr))->GetClass();
      vectorlEunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned int> : new vector<unsigned int>;
   }
   static void *newArray_vectorlEunsignedsPintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned int>[nElements] : new vector<unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPintgR(void *p) {
      delete (static_cast<vector<unsigned int>*>(p));
   }
   static void deleteArray_vectorlEunsignedsPintgR(void *p) {
      delete [] (static_cast<vector<unsigned int>*>(p));
   }
   static void destruct_vectorlEunsignedsPintgR(void *p) {
      typedef vector<unsigned int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned int>

namespace ROOT {
   static TClass *vectorlEshortgR_Dictionary();
   static void vectorlEshortgR_TClassManip(TClass*);
   static void *new_vectorlEshortgR(void *p = nullptr);
   static void *newArray_vectorlEshortgR(Long_t size, void *p);
   static void delete_vectorlEshortgR(void *p);
   static void deleteArray_vectorlEshortgR(void *p);
   static void destruct_vectorlEshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<short>*)
   {
      vector<short> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<short>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<short>", -2, "vector", 389,
                  typeid(vector<short>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEshortgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<short>) );
      instance.SetNew(&new_vectorlEshortgR);
      instance.SetNewArray(&newArray_vectorlEshortgR);
      instance.SetDelete(&delete_vectorlEshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEshortgR);
      instance.SetDestructor(&destruct_vectorlEshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<short> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<short>","std::vector<short, std::allocator<short> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<short>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<short>*>(nullptr))->GetClass();
      vectorlEshortgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEshortgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<short> : new vector<short>;
   }
   static void *newArray_vectorlEshortgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<short>[nElements] : new vector<short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEshortgR(void *p) {
      delete (static_cast<vector<short>*>(p));
   }
   static void deleteArray_vectorlEshortgR(void *p) {
      delete [] (static_cast<vector<short>*>(p));
   }
   static void destruct_vectorlEshortgR(void *p) {
      typedef vector<short> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<short>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = nullptr);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 389,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<double>","std::vector<double, std::allocator<double> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr))->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete (static_cast<vector<double>*>(p));
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] (static_cast<vector<double>*>(p));
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlEboolgR_Dictionary();
   static void vectorlEboolgR_TClassManip(TClass*);
   static void *new_vectorlEboolgR(void *p = nullptr);
   static void *newArray_vectorlEboolgR(Long_t size, void *p);
   static void delete_vectorlEboolgR(void *p);
   static void deleteArray_vectorlEboolgR(void *p);
   static void destruct_vectorlEboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<bool>*)
   {
      vector<bool> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<bool>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<bool>", -2, "vector", 596,
                  typeid(vector<bool>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEboolgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<bool>) );
      instance.SetNew(&new_vectorlEboolgR);
      instance.SetNewArray(&newArray_vectorlEboolgR);
      instance.SetDelete(&delete_vectorlEboolgR);
      instance.SetDeleteArray(&deleteArray_vectorlEboolgR);
      instance.SetDestructor(&destruct_vectorlEboolgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<bool> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<bool>","std::vector<bool, std::allocator<bool> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<bool>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<bool>*>(nullptr))->GetClass();
      vectorlEboolgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEboolgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<bool> : new vector<bool>;
   }
   static void *newArray_vectorlEboolgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<bool>[nElements] : new vector<bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEboolgR(void *p) {
      delete (static_cast<vector<bool>*>(p));
   }
   static void deleteArray_vectorlEboolgR(void *p) {
      delete [] (static_cast<vector<bool>*>(p));
   }
   static void destruct_vectorlEboolgR(void *p) {
      typedef vector<bool> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<bool>

namespace {
  void TriggerDictionaryInitialization_NextSimEvent_Impl() {
    static const char* headers[] = {
"/home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp",
nullptr
    };
    static const char* includePaths[] = {
"/home/emma/devel/resources/root/root/include/",
"/home/emma/Documents/TILGITHUB/build/dict/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "NextSimEvent dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$/home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp")))  nDetTraceStructure;
class __attribute__((annotate("$clingAutoload$/home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp")))  nDetEventStructure;
class __attribute__((annotate("$clingAutoload$/home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp")))  nDetOutputStructure;
class __attribute__((annotate("$clingAutoload$/home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp")))  nDetImplantOutputStructure;
class __attribute__((annotate("$clingAutoload$/home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp")))  nDetDebugStructure;
class __attribute__((annotate("$clingAutoload$/home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp")))  nDetMultiOutputStructure;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "NextSimEvent dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"nDetDebugStructure", payloadCode, "@",
"nDetEventStructure", payloadCode, "@",
"nDetImplantOutputStructure", payloadCode, "@",
"nDetMultiOutputStructure", payloadCode, "@",
"nDetOutputStructure", payloadCode, "@",
"nDetTraceStructure", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("NextSimEvent",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_NextSimEvent_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_NextSimEvent_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_NextSimEvent() {
  TriggerDictionaryInitialization_NextSimEvent_Impl();
}
