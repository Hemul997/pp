#include "stdafx.h"
#include "HospitalManager.h"

static const int DOCTOR_TYPES_NUMBER = 3;

size_t HospitalManager::m_nextID = 1;

HospitalManager::HospitalManager():
	m_id(m_nextID++)
	, m_mutex(std::make_unique<Mutex>())
	, m_randomDevice()
	, m_randomEngine(m_randomDevice())
	, m_distribution()
{
}



HospitalManager::~HospitalManager()
{
}

DoctorType HospitalManager::DoctorAppoint()
{
	const int randomNumber = m_distribution(m_randomEngine);
	switch (randomNumber % DOCTOR_TYPES_NUMBER)
	{
	case 0: 
		return DENTIST;
	case 1:
		return SURGEON;
	default:
		return THERAPIST;
	}
}

void HospitalManager::PatientCare(Patient &patient)
{
	std::printf("Patient%zd went to the queue to the: %s\n", patient.GetPatientID(), GetType().c_str());
	m_mutex->Join();
	
	DoctorType appointedDoctor = DoctorAppoint();
	std::printf("Patient%zd got appointment doctor from %s\n", patient.GetPatientID(), GetType().c_str());

	patient.SetThreatingDoctor(appointedDoctor);

	std::printf("Patient%zd was left %s\n", patient.GetPatientID(), GetType().c_str());

	m_mutex->Release();
}

std::string HospitalManager::GetType() const
{
	return "hospital manager:" + std::to_string(m_id);
}
