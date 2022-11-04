BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "ClinicalReport" (
	"ClinicalReportId"	INTEGER NOT NULL,
	"NurseId"	INTEGER NOT NULL,
	"PatientId"	INTEGER NOT NULL,
	"Report"	TEXT NOT NULL,
	"CreatedDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeletedDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("NurseId") REFERENCES "Patients"("PatientId"),
	FOREIGN KEY("PatientId") REFERENCES "Nurse"("NurseId"),
	PRIMARY KEY("ClinicalReportId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "Clinics" (
	"ClinicId"	INTEGER NOT NULL,
	"Name"	TEXT NOT NULL,
	"Phone"	TEXT,
	"Address"	TEXT,
	"CreatedDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	PRIMARY KEY("ClinicId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "ConsultExam" (
	"ConsultExamId"	INTEGER NOT NULL,
	"ExamDate"	NUMERIC NOT NULL,
	"Price"	REAL,
	"ExamId"	INTEGER NOT NULL,
	"ConsultId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("ExamId") REFERENCES "Exam"("ExamId"),
	FOREIGN KEY("ConsultId") REFERENCES "Consult"("ConsultId"),
	PRIMARY KEY("ConsultExamId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "Exam" (
	"ExamId"	INTEGER NOT NULL,
	"Name"	TEXT NOT NULL,
	"Price"	REAL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	PRIMARY KEY("ExamId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "Medic" (
	"MedicId"	INTEGER NOT NULL,
	"PersonId"	INTEGER NOT NULL,
	"CreateDate"	INTEGER NOT NULL,
	"ModifiedDate"	INTEGER,
	"DeleteDate"	INTEGER,
	"IsEdit"	INTEGER NOT NULL,
	"IsDelete"	INTEGER NOT NULL,
	FOREIGN KEY("PersonId") REFERENCES "Person"("PersonId"),
	PRIMARY KEY("MedicId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "MedicMedicalSpeciality" (
	"MedicId"	INTEGER NOT NULL,
	"MedicalSpecialityId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("MedicId") REFERENCES "Medic"("MedicId"),
	FOREIGN KEY("MedicalSpecialityId") REFERENCES "MedicalSpeciality"("MedicalSpecialityId")
);
CREATE TABLE IF NOT EXISTS "MedicalSchedule" (
	"BeginDate"	NUMERIC NOT NULL,
	"EndDate"	NUMERIC NOT NULL,
	"MedicId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("MedicId") REFERENCES "Medic"("MedicId")
);
CREATE TABLE IF NOT EXISTS "MedicalAppointment" (
	"MedicalAppointmentId"	INTEGER NOT NULL,
	"AppointmentDate"	NUMERIC NOT NULL,
	"Description"	TEXT NOT NULL,
	"Attended"	NUMERIC NOT NULL,
	"PatientId"	INTEGER NOT NULL,
	"MedicId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("MedicId") REFERENCES "Medic"("MedicId"),
	FOREIGN KEY("PatientId") REFERENCES "Patients"("PatientId"),
	PRIMARY KEY("MedicalAppointmentId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "MedicalSpeciality" (
	"MedicalSpecialityId"	INTEGER NOT NULL,
	"Name"	TEXT NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	PRIMARY KEY("MedicalSpecialityId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "Nurse" (
	"NurseId"	INTEGER NOT NULL,
	"PersonId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("PersonId") REFERENCES "Person"("PersonId"),
	PRIMARY KEY("NurseId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "PatientClinic" (
	"PatientClinicId"	INTEGER NOT NULL,
	"PatientId"	INTEGER NOT NULL,
	"ClinicId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("ClinicId") REFERENCES "Clinics"("ClinicId"),
	FOREIGN KEY("PatientId") REFERENCES "Patients"("PatientId"),
	PRIMARY KEY("PatientClinicId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "PatientClinicDetails" (
	"MedicName"	TEXT,
	"Description"	TEXT NOT NULL,
	"PatientClinicId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("PatientClinicId") REFERENCES "PatientClinic"("PatientClinicId")
);
CREATE TABLE IF NOT EXISTS "PatientExam" (
	"PatientExamId"	INTEGER NOT NULL,
	"Price"	REAL,
	"PatientId"	INTEGER NOT NULL,
	"ExamId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("ExamId") REFERENCES "Exam"("ExamId"),
	FOREIGN KEY("PatientId") REFERENCES "Patients"("PatientId"),
	PRIMARY KEY("PatientExamId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "Patients" (
	"PatientId"	INTEGER NOT NULL,
	"PersonId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("PersonId") REFERENCES "Person"("PersonId"),
	PRIMARY KEY("PatientId" AUTOINCREMENT)
);
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
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	PRIMARY KEY("PersonId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "Prescription" (
	"PrescriptionId"	INTEGER NOT NULL,
	"PresciptionDate"	NUMERIC NOT NULL,
	"ConsultId"	INTEGER NOT NULL,
	"PatientId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("ConsultId") REFERENCES "Consult"("ConsultId"),
	FOREIGN KEY("PatientId") REFERENCES "Patients"("PatientId"),
	PRIMARY KEY("PrescriptionId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "PrescriptionDetails" (
	"Medicine"	TEXT NOT NULL,
	"MedicineAmountPerDay"	TEXT,
	"TimeTakeMedicine"	TEXT,
	"MedicineDetails"	TEXT NOT NULL,
	"BeginDate"	NUMERIC NOT NULL,
	"EndDate"	NUMERIC NOT NULL,
	"PrescriptionId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("PrescriptionId") REFERENCES "Prescription"("PrescriptionId")
);
CREATE TABLE IF NOT EXISTS "Consult" (
	"ConsultId"	INTEGER NOT NULL,
	"Price"	REAL NOT NULL,
	"Symptom"	TEXT NOT NULL,
	"Diagnosis"	TEXT NOT NULL,
	"VisitDate"	NUMERIC NOT NULL,
	"PatientId"	INTEGER NOT NULL,
	"ClinicalReportId"	INTEGER NOT NULL,
	"MedicalAppointmentId"	INTEGER NOT NULL,
	"MedicId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("ClinicalReportId") REFERENCES "ClinicalReport"("ClinicalReportId"),
	FOREIGN KEY("MedicalAppointmentId") REFERENCES "MedicalAppointment"("MedicalAppointmentId"),
	FOREIGN KEY("MedicId") REFERENCES "Medic"("MedicId"),
	FOREIGN KEY("PatientId") REFERENCES "Patients"("PatientId"),
	PRIMARY KEY("ConsultId" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "Epicrisis" (
	"EpicrisisId"	INTEGER NOT NULL,
	"EpicrisisCode"	INTEGER NOT NULL,
	"Diagnosis"	TEXT NOT NULL,
	"EpicrisisDate"	NUMERIC NOT NULL,
	"ConsultId"	INTEGER NOT NULL,
	"PrescriptionId"	INTEGER NOT NULL,
	"ConsultExamId"	INTEGER NOT NULL,
	"PatientExamId"	INTEGER NOT NULL,
	"PatientId"	INTEGER NOT NULL,
	"MedicId"	INTEGER NOT NULL,
	"CreateDate"	NUMERIC NOT NULL,
	"ModifiedDate"	NUMERIC,
	"DeleteDate"	NUMERIC,
	"IsEdit"	NUMERIC NOT NULL,
	"IsDelete"	NUMERIC NOT NULL,
	FOREIGN KEY("ConsultExamId") REFERENCES "ConsultExam"("ConsultExamId"),
	FOREIGN KEY("MedicId") REFERENCES "Medic"("MedicId"),
	FOREIGN KEY("ConsultId") REFERENCES "Consult"("ConsultId"),
	FOREIGN KEY("PatientExamId") REFERENCES "PatientExam"("PatientExamId"),
	FOREIGN KEY("PrescriptionId") REFERENCES "Prescription"("PrescriptionId"),
	FOREIGN KEY("PatientId") REFERENCES "Patients"("PatientId"),
	PRIMARY KEY("EpicrisisId" AUTOINCREMENT)
);
COMMIT;
