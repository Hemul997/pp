#include "stdafx.h"
#include "Doctor.h"

const int THREATMENT_TIME = 100;

Doctor::Doctor()
{
}

Doctor::Doctor(DoctorType type)
	:m_type(type)
	,m_mutex(std::make_unique<Mutex>())
{
}

void Doctor::Treat(Patient &patient)
{
	std::printf("Patient%zd went to the queue to the: %s\n", patient.GetPatientID(), GetType().c_str());
	m_mutex->Join();
	std::printf("Patient%zd started treatment: %s\n", patient.GetPatientID(), GetType().c_str());
	Sleep(THREATMENT_TIME);
	std::printf("Patient%zd finished treatment: %s\n", patient.GetPatientID(), GetType().c_str());
	m_mutex->Release();
}

Doctor::~Doctor()
{
}

std::string Doctor::GetType() const
{
	switch (m_type)
	{
	case DoctorType::DENTIST:
		return "dentist";
	case DoctorType::SURGEON:
		return "surgeon";
	default:
		return "therapist";
	}
}