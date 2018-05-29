#pragma once
#include "Patient.h"
#include "Mutex.h"
#include <random>

class HospitalManager
{
public:
	HospitalManager();
	~HospitalManager();
	DoctorType DoctorAppoint();
	void PatientCare(Patient &patient);
	std::string GetType() const;
private:
	size_t m_id;
	static size_t m_nextID;
	std::unique_ptr<Mutex> m_mutex;

	std::random_device m_randomDevice;
	std::mt19937 m_randomEngine;
	std::uniform_int_distribution<> m_distribution;
};

