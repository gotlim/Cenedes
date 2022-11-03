BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "Person" (
	"PersonId"	INTEGER NOT NULL,
	"Carnet"	TEXT NOT NULL,
	"Name"	TEXT NOT NULL,
	"LastName"	TEXT NOT NULL,
	"Age"	INTEGER NOT NULL,
	"Birthday"	NUMERIC NOT NULL,
	"Sexo"	TEXT NOT NULL,
	"Address"	TEXT NOT NULL,
	"Phone"	TEXT,
	PRIMARY KEY("PersonId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "MedicalSpeciality" (
	"MedicalSpecialityId"	INTEGER NOT NULL,
	"Name"	TEXT NOT NULL,
	PRIMARY KEY("MedicalSpecialityId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "Clinics" (
	"ClinicId"	INTEGER NOT NULL,
	"Name"	TEXT NOT NULL,
	"Phone"	TEXT,
	"Address"	TEXT,
	PRIMARY KEY("ClinicId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "Exam" (
	"ExamId"	INTEGER NOT NULL,
	"Name"	TEXT NOT NULL,
	"Price"	REAL,
	PRIMARY KEY("ExamId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "Patients" (
	"PatientId"	INTEGER NOT NULL,
	"FK_PersonPatient"	INTEGER NOT NULL,
	PRIMARY KEY("PatientId" AUTOINCREMENT),
	FOREIGN KEY("FK_PersonPatient") REFERENCES "Person"("PersonId")
);
CREATE TABLE IF NOT EXISTS "Nurse" (
	"NurseId"	INTEGER NOT NULL,
	"FK_PersonNurse"	INTEGER NOT NULL,
	PRIMARY KEY("NurseId" AUTOINCREMENT),
	FOREIGN KEY("FK_PersonNurse") REFERENCES "Person"("PersonId")
);
CREATE TABLE IF NOT EXISTS "ClinicalReport" (
	"ClinicalReportId"	INTEGER NOT NULL,
	"FK_PatientClinicalReport"	INTEGER NOT NULL,
	"FK_NurseClinicalReport"	INTEGER NOT NULL,
	"Report"	TEXT NOT NULL,
	PRIMARY KEY("ClinicalReportId" AUTOINCREMENT),
	FOREIGN KEY("FK_NurseClinicalReport") REFERENCES "Nurse"("NurseId"),
	FOREIGN KEY("FK_PatientClinicalReport") REFERENCES "Patients"("PatientId")
);
CREATE TABLE IF NOT EXISTS "PatientClinic" (
	"PatientClinicId"	INTEGER NOT NULL,
	"FK_PatientPatientClinic"	INTEGER NOT NULL,
	"FK_ClinicClinicPatient"	INTEGER NOT NULL,
	PRIMARY KEY("PatientClinicId" AUTOINCREMENT),
	FOREIGN KEY("FK_ClinicClinicPatient") REFERENCES "Clinics"("ClinicId"),
	FOREIGN KEY("FK_PatientPatientClinic") REFERENCES "Patients"("PatientId")
);
CREATE TABLE IF NOT EXISTS "MedicalSchedule" (
	"BeginDate"	NUMERIC NOT NULL,
	"EndDate"	NUMERIC NOT NULL,
	"FK_MedicMedicalSchedule"	INTEGER NOT NULL,
	FOREIGN KEY("FK_MedicMedicalSchedule") REFERENCES "Medic"("MedicId")
);
CREATE TABLE IF NOT EXISTS "Medic" (
	"MedicId"	INTEGER NOT NULL,
	"FK_PersonMedic"	INTEGER NOT NULL,
	PRIMARY KEY("MedicId" AUTOINCREMENT),
	FOREIGN KEY("FK_PersonMedic") REFERENCES "Person"("PersonId")
);
CREATE TABLE IF NOT EXISTS "MedicMedicalSpeciality" (
	"FK_MedicMMedicalSpeciality"	INTEGER NOT NULL,
	"FK_MedicalSpeciality"	INTEGER NOT NULL,
	FOREIGN KEY("FK_MedicMMedicalSpeciality") REFERENCES "Medic"("MedicId"),
	FOREIGN KEY("FK_MedicalSpeciality") REFERENCES "MedicalSpeciality"("MedicalSpecialityId")
);
CREATE TABLE IF NOT EXISTS "Consult" (
	"ConsultId"	INTEGER NOT NULL,
	"Price"	REAL NOT NULL,
	"Symptom"	TEXT NOT NULL,
	"Diagnosis"	TEXT NOT NULL,
	"VisitDate"	NUMERIC NOT NULL,
	"FK_PatientConsult"	INTEGER NOT NULL,
	"FK_ClinicalReportConsult"	INTEGER,
	"FK_MedicalAppointmentConsult"	INTEGER,
	"FK_MedicConsult"	INTEGER,
	PRIMARY KEY("ConsultId" AUTOINCREMENT),
	FOREIGN KEY("FK_MedicalAppointmentConsult") REFERENCES "MedicalAppointment"("MedicalAppointmentId"),
	FOREIGN KEY("FK_ClinicalReportConsult") REFERENCES "ClinicalReport"("ClinicalReportId"),
	FOREIGN KEY("FK_PatientConsult") REFERENCES "Patients"("PatientId"),
	FOREIGN KEY("FK_MedicConsult") REFERENCES "Medic"("MedicId")
);
CREATE TABLE IF NOT EXISTS "Prescription" (
	"PrescriptionId"	INTEGER NOT NULL,
	"PresciptionDate"	NUMERIC NOT NULL,
	"FK_ConsultPrescription"	INTEGER NOT NULL,
	"FK_PatientPrescription"	INTEGER NOT NULL,
	PRIMARY KEY("PrescriptionId" AUTOINCREMENT),
	FOREIGN KEY("FK_ConsultPrescription") REFERENCES "Consult"("ConsultId"),
	FOREIGN KEY("FK_PatientPrescription") REFERENCES "Patients"("PatientId")
);
CREATE TABLE IF NOT EXISTS "PrescriptionDetails" (
	"Medicine"	TEXT NOT NULL,
	"MedicineAmountPerDay"	TEXT,
	"TimeTakeMedicine"	TEXT,
	"MedicineDetails"	TEXT NOT NULL,
	"BeginDate"	NUMERIC NOT NULL,
	"EndDate"	NUMERIC NOT NULL,
	"FK_PrescriptionPDetails"	INTEGER NOT NULL,
	FOREIGN KEY("FK_PrescriptionPDetails") REFERENCES "Prescription"("PrescriptionId")
);
CREATE TABLE IF NOT EXISTS "ConsultExam" (
	"ConsultExamId"	INTEGER NOT NULL,
	"ExamDate"	NUMERIC NOT NULL,
	"Price"	REAL,
	"FK_ExamConsultExam"	INTEGER NOT NULL,
	"FK_ConsultConsultExam"	INTEGER NOT NULL,
	PRIMARY KEY("ConsultExamId" AUTOINCREMENT),
	FOREIGN KEY("FK_ExamConsultExam") REFERENCES "Exam"("ExamId"),
	FOREIGN KEY("FK_ConsultConsultExam") REFERENCES "Consult"("ConsultId")
);
CREATE TABLE IF NOT EXISTS "PatientClinicDetails" (
	"MedicName"	INTEGER,
	"Description"	INTEGER NOT NULL,
	"FK_PClinicPatientClinicDetails"	INTEGER NOT NULL,
	FOREIGN KEY("FK_PClinicPatientClinicDetails") REFERENCES "PatientClinic"("PatientClinicId")
);
CREATE TABLE IF NOT EXISTS "PatientExam" (
	"PatientExamId"	INTEGER NOT NULL,
	"Price"	REAL,
	"FK_PatientPatientExam"	INTEGER NOT NULL,
	"FK_ExamPatientExam"	INTEGER NOT NULL,
	PRIMARY KEY("PatientExamId" AUTOINCREMENT),
	FOREIGN KEY("FK_ExamPatientExam") REFERENCES "Exam"("ExamId"),
	FOREIGN KEY("FK_PatientPatientExam") REFERENCES "Patients"("PatientId")
);
CREATE TABLE IF NOT EXISTS "Epicrisis" (
	"EpicrisisId"	INTEGER NOT NULL,
	"EpicrisisCode"	INTEGER NOT NULL,
	"Diagnosis"	TEXT NOT NULL,
	"EpicrisisDate"	NUMERIC NOT NULL,
	"FK_ConsultEpicrisis"	INTEGER NOT NULL,
	"FK_PrescriptionEpicrisis"	BLOB NOT NULL,
	"FK_ConsultExamEpicrisis"	INTEGER NOT NULL,
	"FK_PatientExamEpicrisis"	INTEGER NOT NULL,
	"FK_PatientEpicrisis"	INTEGER NOT NULL,
	"FK_MedicEpicrisis"	INTEGER NOT NULL,
	PRIMARY KEY("EpicrisisId" AUTOINCREMENT),
	FOREIGN KEY("FK_PatientExamEpicrisis") REFERENCES "PatientExam"("PatientExamId"),
	FOREIGN KEY("FK_PrescriptionEpicrisis") REFERENCES "Prescription"("PrescriptionId"),
	FOREIGN KEY("FK_ConsultEpicrisis") REFERENCES "Consult"("ConsultId"),
	FOREIGN KEY("FK_PatientEpicrisis") REFERENCES "Patients"("PatientId"),
	FOREIGN KEY("FK_ConsultExamEpicrisis") REFERENCES "ConsultExam"("ConsultExamId")
);
CREATE TABLE IF NOT EXISTS "MedicalAppointment" (
	"MedicalAppointmentId"	INTEGER NOT NULL,
	"AppointmentDate"	NUMERIC NOT NULL,
	"Description"	TEXT NOT NULL,
	"Attended"	NUMERIC NOT NULL,
	"FK_PatientMedicalAppointment"	INTEGER NOT NULL,
	"FK_MedicMedicalAppointment"	INTEGER NOT NULL,
	PRIMARY KEY("MedicalAppointmentId" AUTOINCREMENT),
	FOREIGN KEY("FK_MedicMedicalAppointment") REFERENCES "Medic"("MedicId"),
	FOREIGN KEY("FK_PatientMedicalAppointment") REFERENCES "Patients"("PatientId")
);
COMMIT;
