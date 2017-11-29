#ifndef SimG4Core_SensitiveDetector_SensitiveDetectorMaker_h
#define SimG4Core_SensitiveDetector_SensitiveDetectorMaker_h
// -*- C++ -*-
//
// Package:     SensitiveDetector
// Class  :     SensitiveDetectorMaker
// 
//
// Original Author:  
//         Created:  Mon Nov 14 11:56:05 EST 2005
//

// system include files
#include <memory>

// user include files
#include "SimG4Core/SensitiveDetector/interface/SensitiveDetectorMakerBase.h"
#include "SimG4Core/Notification/interface/SimActivityRegistryEnroller.h"

// forward declarations

template<class T>
class SensitiveDetectorMaker : public SensitiveDetectorMakerBase
{

   public:
     SensitiveDetectorMaker(){}
     //virtual ~SensitiveDetectorMaker();

      // ---------- const member functions ---------------------
      void make(const std::string& iname,
			const DDCompactView& cpv,
			const SensitiveDetectorCatalog& clg,
			const edm::ParameterSet& p,
			const SimTrackManager* m,
			SimActivityRegistry& reg,
			std::unique_ptr<SensitiveTkDetector>& oTK,
			std::unique_ptr<SensitiveCaloDetector>& oCalo) const override
      {
	std::unique_ptr<T> returnValue(new T(iname, cpv, clg, p, m));
	SimActivityRegistryEnroller::enroll(reg, returnValue.get());

	this->convertTo(returnValue.get(), oTK,oCalo);
	//ownership was passed in the previous function
	returnValue.release();
      }

   private:
      SensitiveDetectorMaker(const SensitiveDetectorMaker&) = delete; // stop default

      const SensitiveDetectorMaker& operator=(const SensitiveDetectorMaker&) = delete; // stop default

};


#endif
