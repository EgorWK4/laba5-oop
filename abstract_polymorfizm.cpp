
#include <iostream>
#include <string>



class Student
{
 
    std::string m_first_name;
    std::string m_second_name;
    static unsigned m_count;
    
public:
    Student(std::string first_name = "", std::string second_name = "") : m_first_name(first_name) , m_second_name(second_name) 
    {
        ++m_count;
    }
    void set_first_name(const std::string first_name) { m_first_name = first_name; }
    void set_second_name(const std::string second_name) { m_second_name = second_name; }

    std::string get_first_name() const { return m_first_name; }
    std::string get_second_name() const { return m_second_name; }
   
     virtual void show_info()
    {
        std::cout << "first name = "<< m_first_name << std::endl;
        std::cout <<"second name = "<< m_second_name << std::endl;
        std::cout << "count objects = " << m_count << std::endl;
    }
     
};

unsigned Student::m_count = 0;

class Graduate_student : public Student
{
    std::string m_bachelor_thesis;
    unsigned m_salary;

public:

    void set_bachelor_thesis(const std::string bachelor_thesis) { m_bachelor_thesis = bachelor_thesis; }
    void set_salary(const unsigned salary) { m_salary = salary; }

    std::string get_bachelor_thesis() const { return m_bachelor_thesis; }
    unsigned get_salary() const { return m_salary; }

    Graduate_student(std::string bachelor_thesis = "", unsigned salary = 0) : m_bachelor_thesis(bachelor_thesis), m_salary(salary) {}

    void show_info() override
    {
        Student::show_info();
        std::cout << "bachelor thesis is :" << m_bachelor_thesis;
        std::cout << "salary is " << m_salary;
    }

};

class Graduate_year : public Student
{
    std::string m_internship;
    bool m_driver_license;

public:

    Graduate_year(std::string internship = "", bool driver_license = false) : m_internship(internship), m_driver_license(driver_license) {}

    void show_info() override
    {
        Student::show_info();
        std::cout << "company intership = " << m_internship;
        std::cout << "has driver license = " << m_driver_license;
    }

    void set_internship(const std::string internship) { m_internship = internship; }
    void set_driver_license(const bool drive_license) { m_driver_license = drive_license; }

    std::string get_internship() const { return m_internship; }
    bool get_m_driver_license() const { return m_driver_license; }
};
 

int main()
{

    Student* a = new Graduate_student();
    Graduate_student* c = (Graduate_student*)a;
    c->set_first_name("Alex");
    c->set_second_name("Ng");
    c->set_salary(1000);
    c->set_bachelor_thesis("Deriving Control Flow Graphs from JavaScript programs");
    c->show_info();

    Student* b = new Graduate_year();
    Graduate_year* d = (Graduate_year*)b;

    std::cout << ";" << std::endl;
    std::cout << std::endl;

    d->set_first_name("Egor");
    d->set_second_name("Trubetskoy");
    d->set_internship("McKinsey & Company");
    d->set_driver_license(0);
    d->show_info();
   
}

