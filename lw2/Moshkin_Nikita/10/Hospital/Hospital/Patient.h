#pragma once

#include "DoctorType.h"
class Patient
{
public:
	Patient();
	~Patient();
	size_t GetPatientID() const;
	void SetThreatingDoctor(DoctorType type);
	DoctorType GetThreatingDoctor() const;
private:
	DoctorType m_treatingDoctor;
	size_t m_patientID;
	static size_t m_nextPatientID;
};

