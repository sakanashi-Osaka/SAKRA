// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME MyclassDict
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

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "RunInfo.hpp"
#include "V1730ZLEHeader.hpp"
#include "ChEvent.hpp"
#include "V1730ZLE.hpp"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TRunInfo(void *p = 0);
   static void *newArray_TRunInfo(Long_t size, void *p);
   static void delete_TRunInfo(void *p);
   static void deleteArray_TRunInfo(void *p);
   static void destruct_TRunInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRunInfo*)
   {
      ::TRunInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TRunInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TRunInfo", ::TRunInfo::Class_Version(), "RunInfo.hpp", 6,
                  typeid(::TRunInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TRunInfo::Dictionary, isa_proxy, 4,
                  sizeof(::TRunInfo) );
      instance.SetNew(&new_TRunInfo);
      instance.SetNewArray(&newArray_TRunInfo);
      instance.SetDelete(&delete_TRunInfo);
      instance.SetDeleteArray(&deleteArray_TRunInfo);
      instance.SetDestructor(&destruct_TRunInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRunInfo*)
   {
      return GenerateInitInstanceLocal((::TRunInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRunInfo*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TV1730ZLEHeader(void *p = 0);
   static void *newArray_TV1730ZLEHeader(Long_t size, void *p);
   static void delete_TV1730ZLEHeader(void *p);
   static void deleteArray_TV1730ZLEHeader(void *p);
   static void destruct_TV1730ZLEHeader(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TV1730ZLEHeader*)
   {
      ::TV1730ZLEHeader *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TV1730ZLEHeader >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TV1730ZLEHeader", ::TV1730ZLEHeader::Class_Version(), "V1730ZLEHeader.hpp", 7,
                  typeid(::TV1730ZLEHeader), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TV1730ZLEHeader::Dictionary, isa_proxy, 4,
                  sizeof(::TV1730ZLEHeader) );
      instance.SetNew(&new_TV1730ZLEHeader);
      instance.SetNewArray(&newArray_TV1730ZLEHeader);
      instance.SetDelete(&delete_TV1730ZLEHeader);
      instance.SetDeleteArray(&deleteArray_TV1730ZLEHeader);
      instance.SetDestructor(&destruct_TV1730ZLEHeader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TV1730ZLEHeader*)
   {
      return GenerateInitInstanceLocal((::TV1730ZLEHeader*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TV1730ZLEHeader*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TChEvent(void *p = 0);
   static void *newArray_TChEvent(Long_t size, void *p);
   static void delete_TChEvent(void *p);
   static void deleteArray_TChEvent(void *p);
   static void destruct_TChEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TChEvent*)
   {
      ::TChEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TChEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TChEvent", ::TChEvent::Class_Version(), "ChEvent.hpp", 9,
                  typeid(::TChEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TChEvent::Dictionary, isa_proxy, 4,
                  sizeof(::TChEvent) );
      instance.SetNew(&new_TChEvent);
      instance.SetNewArray(&newArray_TChEvent);
      instance.SetDelete(&delete_TChEvent);
      instance.SetDeleteArray(&deleteArray_TChEvent);
      instance.SetDestructor(&destruct_TChEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TChEvent*)
   {
      return GenerateInitInstanceLocal((::TChEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TChEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TV1730ZLE(void *p = 0);
   static void *newArray_TV1730ZLE(Long_t size, void *p);
   static void delete_TV1730ZLE(void *p);
   static void deleteArray_TV1730ZLE(void *p);
   static void destruct_TV1730ZLE(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TV1730ZLE*)
   {
      ::TV1730ZLE *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TV1730ZLE >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TV1730ZLE", ::TV1730ZLE::Class_Version(), "V1730ZLE.hpp", 9,
                  typeid(::TV1730ZLE), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TV1730ZLE::Dictionary, isa_proxy, 4,
                  sizeof(::TV1730ZLE) );
      instance.SetNew(&new_TV1730ZLE);
      instance.SetNewArray(&newArray_TV1730ZLE);
      instance.SetDelete(&delete_TV1730ZLE);
      instance.SetDeleteArray(&deleteArray_TV1730ZLE);
      instance.SetDestructor(&destruct_TV1730ZLE);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TV1730ZLE*)
   {
      return GenerateInitInstanceLocal((::TV1730ZLE*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TV1730ZLE*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TRunInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TRunInfo::Class_Name()
{
   return "TRunInfo";
}

//______________________________________________________________________________
const char *TRunInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRunInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TRunInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRunInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TRunInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRunInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TRunInfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRunInfo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TV1730ZLEHeader::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TV1730ZLEHeader::Class_Name()
{
   return "TV1730ZLEHeader";
}

//______________________________________________________________________________
const char *TV1730ZLEHeader::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TV1730ZLEHeader*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TV1730ZLEHeader::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TV1730ZLEHeader*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TV1730ZLEHeader::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TV1730ZLEHeader*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TV1730ZLEHeader::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TV1730ZLEHeader*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TChEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TChEvent::Class_Name()
{
   return "TChEvent";
}

//______________________________________________________________________________
const char *TChEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TChEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TChEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TChEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TChEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TChEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TChEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TChEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TV1730ZLE::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TV1730ZLE::Class_Name()
{
   return "TV1730ZLE";
}

//______________________________________________________________________________
const char *TV1730ZLE::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TV1730ZLE*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TV1730ZLE::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TV1730ZLE*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TV1730ZLE::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TV1730ZLE*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TV1730ZLE::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TV1730ZLE*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TRunInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class TRunInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TRunInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(TRunInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRunInfo(void *p) {
      return  p ? new(p) ::TRunInfo : new ::TRunInfo;
   }
   static void *newArray_TRunInfo(Long_t nElements, void *p) {
      return p ? new(p) ::TRunInfo[nElements] : new ::TRunInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRunInfo(void *p) {
      delete ((::TRunInfo*)p);
   }
   static void deleteArray_TRunInfo(void *p) {
      delete [] ((::TRunInfo*)p);
   }
   static void destruct_TRunInfo(void *p) {
      typedef ::TRunInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TRunInfo

//______________________________________________________________________________
void TV1730ZLEHeader::Streamer(TBuffer &R__b)
{
   // Stream an object of class TV1730ZLEHeader.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TV1730ZLEHeader::Class(),this);
   } else {
      R__b.WriteClassBuffer(TV1730ZLEHeader::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TV1730ZLEHeader(void *p) {
      return  p ? new(p) ::TV1730ZLEHeader : new ::TV1730ZLEHeader;
   }
   static void *newArray_TV1730ZLEHeader(Long_t nElements, void *p) {
      return p ? new(p) ::TV1730ZLEHeader[nElements] : new ::TV1730ZLEHeader[nElements];
   }
   // Wrapper around operator delete
   static void delete_TV1730ZLEHeader(void *p) {
      delete ((::TV1730ZLEHeader*)p);
   }
   static void deleteArray_TV1730ZLEHeader(void *p) {
      delete [] ((::TV1730ZLEHeader*)p);
   }
   static void destruct_TV1730ZLEHeader(void *p) {
      typedef ::TV1730ZLEHeader current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TV1730ZLEHeader

//______________________________________________________________________________
void TChEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class TChEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TChEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(TChEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TChEvent(void *p) {
      return  p ? new(p) ::TChEvent : new ::TChEvent;
   }
   static void *newArray_TChEvent(Long_t nElements, void *p) {
      return p ? new(p) ::TChEvent[nElements] : new ::TChEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_TChEvent(void *p) {
      delete ((::TChEvent*)p);
   }
   static void deleteArray_TChEvent(void *p) {
      delete [] ((::TChEvent*)p);
   }
   static void destruct_TChEvent(void *p) {
      typedef ::TChEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TChEvent

//______________________________________________________________________________
void TV1730ZLE::Streamer(TBuffer &R__b)
{
   // Stream an object of class TV1730ZLE.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TV1730ZLE::Class(),this);
   } else {
      R__b.WriteClassBuffer(TV1730ZLE::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TV1730ZLE(void *p) {
      return  p ? new(p) ::TV1730ZLE : new ::TV1730ZLE;
   }
   static void *newArray_TV1730ZLE(Long_t nElements, void *p) {
      return p ? new(p) ::TV1730ZLE[nElements] : new ::TV1730ZLE[nElements];
   }
   // Wrapper around operator delete
   static void delete_TV1730ZLE(void *p) {
      delete ((::TV1730ZLE*)p);
   }
   static void deleteArray_TV1730ZLE(void *p) {
      delete [] ((::TV1730ZLE*)p);
   }
   static void destruct_TV1730ZLE(void *p) {
      typedef ::TV1730ZLE current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TV1730ZLE

namespace ROOT {
   static TClass *vectorlEunsignedsPshortgR_Dictionary();
   static void vectorlEunsignedsPshortgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPshortgR(void *p = 0);
   static void *newArray_vectorlEunsignedsPshortgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPshortgR(void *p);
   static void deleteArray_vectorlEunsignedsPshortgR(void *p);
   static void destruct_vectorlEunsignedsPshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned short>*)
   {
      vector<unsigned short> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned short>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned short>", -2, "vector", 386,
                  typeid(vector<unsigned short>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPshortgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned short>) );
      instance.SetNew(&new_vectorlEunsignedsPshortgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPshortgR);
      instance.SetDelete(&delete_vectorlEunsignedsPshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPshortgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned short> >()));

      ::ROOT::AddClassAlternate("vector<unsigned short>","std::vector<unsigned short, std::allocator<unsigned short> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<unsigned short>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<unsigned short>*)0x0)->GetClass();
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
      delete ((vector<unsigned short>*)p);
   }
   static void deleteArray_vectorlEunsignedsPshortgR(void *p) {
      delete [] ((vector<unsigned short>*)p);
   }
   static void destruct_vectorlEunsignedsPshortgR(void *p) {
      typedef vector<unsigned short> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned short>

namespace ROOT {
   static TClass *vectorlETV1730ZLEgR_Dictionary();
   static void vectorlETV1730ZLEgR_TClassManip(TClass*);
   static void *new_vectorlETV1730ZLEgR(void *p = 0);
   static void *newArray_vectorlETV1730ZLEgR(Long_t size, void *p);
   static void delete_vectorlETV1730ZLEgR(void *p);
   static void deleteArray_vectorlETV1730ZLEgR(void *p);
   static void destruct_vectorlETV1730ZLEgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TV1730ZLE>*)
   {
      vector<TV1730ZLE> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TV1730ZLE>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TV1730ZLE>", -2, "vector", 386,
                  typeid(vector<TV1730ZLE>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETV1730ZLEgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TV1730ZLE>) );
      instance.SetNew(&new_vectorlETV1730ZLEgR);
      instance.SetNewArray(&newArray_vectorlETV1730ZLEgR);
      instance.SetDelete(&delete_vectorlETV1730ZLEgR);
      instance.SetDeleteArray(&deleteArray_vectorlETV1730ZLEgR);
      instance.SetDestructor(&destruct_vectorlETV1730ZLEgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TV1730ZLE> >()));

      ::ROOT::AddClassAlternate("vector<TV1730ZLE>","std::vector<TV1730ZLE, std::allocator<TV1730ZLE> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TV1730ZLE>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETV1730ZLEgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TV1730ZLE>*)0x0)->GetClass();
      vectorlETV1730ZLEgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETV1730ZLEgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETV1730ZLEgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TV1730ZLE> : new vector<TV1730ZLE>;
   }
   static void *newArray_vectorlETV1730ZLEgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TV1730ZLE>[nElements] : new vector<TV1730ZLE>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETV1730ZLEgR(void *p) {
      delete ((vector<TV1730ZLE>*)p);
   }
   static void deleteArray_vectorlETV1730ZLEgR(void *p) {
      delete [] ((vector<TV1730ZLE>*)p);
   }
   static void destruct_vectorlETV1730ZLEgR(void *p) {
      typedef vector<TV1730ZLE> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TV1730ZLE>

namespace ROOT {
   static TClass *vectorlETChEventgR_Dictionary();
   static void vectorlETChEventgR_TClassManip(TClass*);
   static void *new_vectorlETChEventgR(void *p = 0);
   static void *newArray_vectorlETChEventgR(Long_t size, void *p);
   static void delete_vectorlETChEventgR(void *p);
   static void deleteArray_vectorlETChEventgR(void *p);
   static void destruct_vectorlETChEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TChEvent>*)
   {
      vector<TChEvent> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TChEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TChEvent>", -2, "vector", 386,
                  typeid(vector<TChEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETChEventgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TChEvent>) );
      instance.SetNew(&new_vectorlETChEventgR);
      instance.SetNewArray(&newArray_vectorlETChEventgR);
      instance.SetDelete(&delete_vectorlETChEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlETChEventgR);
      instance.SetDestructor(&destruct_vectorlETChEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TChEvent> >()));

      ::ROOT::AddClassAlternate("vector<TChEvent>","std::vector<TChEvent, std::allocator<TChEvent> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TChEvent>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETChEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TChEvent>*)0x0)->GetClass();
      vectorlETChEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETChEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETChEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TChEvent> : new vector<TChEvent>;
   }
   static void *newArray_vectorlETChEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TChEvent>[nElements] : new vector<TChEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETChEventgR(void *p) {
      delete ((vector<TChEvent>*)p);
   }
   static void deleteArray_vectorlETChEventgR(void *p) {
      delete [] ((vector<TChEvent>*)p);
   }
   static void destruct_vectorlETChEventgR(void *p) {
      typedef vector<TChEvent> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TChEvent>

namespace ROOT {
   static TClass *bitsetlE16gR_Dictionary();
   static void bitsetlE16gR_TClassManip(TClass*);
   static void *new_bitsetlE16gR(void *p = 0);
   static void *newArray_bitsetlE16gR(Long_t size, void *p);
   static void delete_bitsetlE16gR(void *p);
   static void deleteArray_bitsetlE16gR(void *p);
   static void destruct_bitsetlE16gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const bitset<16>*)
   {
      bitset<16> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(bitset<16>));
      static ::ROOT::TGenericClassInfo 
         instance("bitset<16>", 2, "bitset", 751,
                  typeid(bitset<16>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &bitsetlE16gR_Dictionary, isa_proxy, 0,
                  sizeof(bitset<16>) );
      instance.SetNew(&new_bitsetlE16gR);
      instance.SetNewArray(&newArray_bitsetlE16gR);
      instance.SetDelete(&delete_bitsetlE16gR);
      instance.SetDeleteArray(&deleteArray_bitsetlE16gR);
      instance.SetDestructor(&destruct_bitsetlE16gR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback<Internal::TStdBitsetHelper< bitset<16> > >()));

      ::ROOT::AddClassAlternate("bitset<16>","std::bitset<16ul>");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const bitset<16>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *bitsetlE16gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const bitset<16>*)0x0)->GetClass();
      bitsetlE16gR_TClassManip(theClass);
   return theClass;
   }

   static void bitsetlE16gR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_bitsetlE16gR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) bitset<16> : new bitset<16>;
   }
   static void *newArray_bitsetlE16gR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) bitset<16>[nElements] : new bitset<16>[nElements];
   }
   // Wrapper around operator delete
   static void delete_bitsetlE16gR(void *p) {
      delete ((bitset<16>*)p);
   }
   static void deleteArray_bitsetlE16gR(void *p) {
      delete [] ((bitset<16>*)p);
   }
   static void destruct_bitsetlE16gR(void *p) {
      typedef bitset<16> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class bitset<16>

namespace {
  void TriggerDictionaryInitialization_MyclassDict_Impl() {
    static const char* headers[] = {
"RunInfo.hpp",
"V1730ZLEHeader.hpp",
"ChEvent.hpp",
"V1730ZLE.hpp",
0
    };
    static const char* includePaths[] = {
"/usr/local/root/include/root",
"/home/quser/exp/SAKRA/ana_class/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "MyclassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$ChEvent.hpp")))  TChEvent;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$V1730ZLE.hpp")))  TV1730ZLE;
class __attribute__((annotate("$clingAutoload$RunInfo.hpp")))  TRunInfo;
class __attribute__((annotate("$clingAutoload$V1730ZLEHeader.hpp")))  TV1730ZLEHeader;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "MyclassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "RunInfo.hpp"
#include "V1730ZLEHeader.hpp"
#include "ChEvent.hpp"
#include "V1730ZLE.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TChEvent", payloadCode, "@",
"TRunInfo", payloadCode, "@",
"TV1730ZLE", payloadCode, "@",
"TV1730ZLEHeader", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("MyclassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_MyclassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_MyclassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_MyclassDict() {
  TriggerDictionaryInitialization_MyclassDict_Impl();
}
