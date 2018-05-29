#include "stdafx.h"
#include "Patient.h"

size_t Patient::m_nextPatientID = 1;

Patient::Patient():
	m_patientID(m_nextPatientID++)
{
}

Patient::~Patient()
{
}


size_t Patient::GetPatientID() const
{
	return m_patientID;
}

void Patient::SetThreatingDoctor(DoctorType type)
{
	m_treatingDoctor = type;
}

DoctorType Patient::GetThreatingDoctor() const
{
	return m_treatingDoctor;
}
