/* Name : Avinash Singh
 * Course : OOP244 B
 * File : Enrollment.h
 */


#ifndef SICT_WEATHER_H_
#define SICT_WEATHER_H_

namespace sict {
	class Enrollment {
		private:
			char name_[31];
			char code_[11];
			int year_;
			int semester_;
			int slot_;
			bool enrolled_;
		public:
			Enrollment();
			Enrollment(char *name,char *code,int year,int semester,int time)
			{
				name_=name;
				code_=code;
				year_=year;
				semester_=semester;
				slot_=time;
				enrolled_=false;
			}
			bool isValid()const;
			void setEmpty();
			bool isEnrolled() const;
			void display(bool nameOnly)const;
			void set(const char* name,const char* code,int year,int semester,int time, bool enrolled=false);
			bool hasConflict(const Enrollment &other) const;
	};
}




#endif
