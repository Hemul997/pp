#pragma once
#include "DoctorType.h"
#include "Patient.h"
#include "Mutex.h"

class Doctor
{
public:
	Doctor();
	~Doctor();
	Doctor(DoctorType type);
	void Treat(Patient &patient);
	std::string GetType() const;
private:
	DoctorType m_type;
	std::unique_ptr<Mutex> m_mutex;
};

