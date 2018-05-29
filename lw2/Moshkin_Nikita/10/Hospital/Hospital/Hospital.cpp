#include "stdafx.h"
#include "HospitalManager.h"
#include "Doctor.h"
#include "Patient.h"
#include "ThreadHandler.h"

using namespace std;

const string helpMessage = "Use <Hospital.exe> <patients count>";
const string errorMessage = "Error of arguments! Use <Hospital.exe> --help to find startup parameters";

struct ThreadData {
	ThreadData()
	{
		m_firstManager = make_unique<HospitalManager>();
		m_secondManager = make_unique<HospitalManager>();
		m_dentist = make_unique<Doctor>(DENTIST);
		m_surgeon = make_unique<Doctor>(SURGEON);
		m_therapist = make_unique<Doctor>(THERAPIST);
	}
	unique_ptr<HospitalManager> m_firstManager, m_secondManager;
	unique_ptr<Doctor> m_dentist, m_surgeon, m_therapist;
};


DWORD WINAPI ThreadProc(LPVOID param) {
	ThreadData *data = (ThreadData *)param;
	Patient patient;
	if (patient.GetPatientID() % 2 != 0)
	{
		data->m_firstManager->PatientCare(patient);
	}
	else
	{
		data->m_secondManager->PatientCare(patient);
	}
	switch (patient.GetThreatingDoctor())
	{
	case DENTIST:
		data->m_dentist->Treat(patient);
		break;
	case SURGEON:
		data->m_surgeon->Treat(patient);
		break;
	case THERAPIST:
		data->m_therapist->Treat(patient);
		break;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << errorMessage << endl;
		return 1;
		
	}
	else {
		if (string(argv[1]) == "--help") {
			cout << helpMessage << endl;
			return 0;
		}
			
	}
	size_t patientsCount = atoi(argv[1]);

	ThreadHandler threadHandler;
	ThreadData threadData;
	for (size_t i = 0; i < patientsCount; ++i) {
		threadHandler.PushThread(ThreadProc, &threadData);
	}
	threadHandler.JoinAll();

	return 0;
}