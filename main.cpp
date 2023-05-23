#include<iostream>
#include<windows.h>

class Figure 
{
protected:
    int sides_count;
    std::string name;

public:
    Figure()
    {
        sides_count = 0;
        name = "Фигура:";
    }

    Figure(int sides_count, std::string name)
    {
        this->sides_count = sides_count;
        this->name = name;
    }

    std::string get_name()
    {
        return name;
    };

    int get_sides_count()
    {
        return sides_count;
    };

    bool virtual check()
    {
        if (get_sides_count() == 0) 
        {
            return true;
        }
        else 
        {
            return false;
        }
    };

    void virtual print_info()
    {
        std::cout << get_name() << std::endl;
        if (check() == 1) 
        {
            std::cout << "Правильная" << std::endl;
        }
        else 
        {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_sides_count() << std::endl;
    }
};

class Triangle : public Figure
{
public:

    int length_side_a;
    int length_side_b;
    int length_side_c;
    int value_angle_A;
    int value_angle_B;
    int value_angle_C;

    Triangle()
    {
        length_side_a = 10;
        length_side_b = 20;
        length_side_c = 30;
        value_angle_A = 50;
        value_angle_B = 60;
        value_angle_C = 70;
        sides_count = 3;
        name = "Треугольник:";
    }

    Triangle(int length_side_a, int length_side_b, int length_side_c,
        int value_angle_A, int value_angle_B, int value_angle_C) : Triangle()
    {
        this->length_side_a = length_side_a;
        this->length_side_b = length_side_b;
        this->length_side_c = length_side_c;
        this->value_angle_A = value_angle_A;
        this->value_angle_B = value_angle_B;
        this->value_angle_C = value_angle_C;
    }

    int get_lenght_side_a()
    {
        return length_side_a;
    };

    int get_lenght_side_b()
    {
        return length_side_b;
    };

    int get_lenght_side_c()
    {
        return length_side_c;
    };

    int get_value_angle_A()
    {
        return value_angle_A;
    };

    int get_value_angle_B()
    {
        return value_angle_B;
    };

    int get_value_angle_C()
    {
        return value_angle_C;
    };

    bool check() override 
    {
        if ((sides_count == 3) && (value_angle_A + value_angle_B + value_angle_C == 180))
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны:" << " a=" << get_lenght_side_a() << " b=" << get_lenght_side_b() << " c=" << get_lenght_side_c() << std::endl;
        std::cout << "Углы:" << " А=" << get_value_angle_A() << " B=" << get_value_angle_B() << " C=" << get_value_angle_C() << std::endl << std::endl;
    }
};

class Right_triangle : public Triangle
{
public:
    Right_triangle()
    {
        value_angle_C = 90;
        name = "Прямоугольный треугольник:";
    }

    Right_triangle(int length_side_a, int length_side_b, int length_side_c,
        int value_angle_A, int value_angle_B) : Right_triangle()
    {
        this->length_side_a = length_side_a;
        this->length_side_b = length_side_b;
        this->length_side_c = length_side_c;
        this->value_angle_A = value_angle_A;
        this->value_angle_B = value_angle_B;
    }

    bool check() override
    {
        if ((sides_count == 3) && (value_angle_C == 90) && (value_angle_A + value_angle_B + value_angle_C == 180))
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};

class Isosceles_triangle : public Triangle 
{
public:
    Isosceles_triangle()
    {
        length_side_a = 10;
        length_side_c = 10;
        value_angle_A = 50;
        value_angle_C = 50;
        name = "Равнобедренный треугольник:";
    }

    Isosceles_triangle(int length_side_a, int length_side_b,
        int value_angle_A, int value_angle_B) : Isosceles_triangle()
    {
        this->length_side_a = length_side_a;
        this->length_side_b = length_side_b;
        length_side_c = length_side_c;
        this->value_angle_A = value_angle_A;
        this->value_angle_B = value_angle_B;
        value_angle_C = value_angle_A;
    }

    bool check() override 
    {
        if ((sides_count == 3) && (length_side_a == length_side_c) && (value_angle_A == value_angle_C) && (value_angle_A + value_angle_B + value_angle_C == 180))
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};

class Equilateral_triangle : public Triangle 
{
public:
    Equilateral_triangle()
    {
        length_side_a = 30;
        length_side_b = 30;
        length_side_c = 30;
        value_angle_A = 60;
        value_angle_B = 60;
        value_angle_C = 60;
        name = "Равносторонний треугольник:";
    }

    Equilateral_triangle(int length_side_a) : Equilateral_triangle()
    {
        this->length_side_a = length_side_a;
        length_side_b = length_side_a;
        length_side_c = length_side_b;
        value_angle_A = 60;
        value_angle_B = value_angle_A;
        value_angle_C = value_angle_B;
    }

    bool check() override 
    {
        if ((sides_count == 3) &&
            ((length_side_a == length_side_b) && (length_side_a == length_side_c) && (length_side_b == length_side_c)) &&
            (value_angle_A == 60) && (value_angle_B == 60) && (value_angle_C == 60))
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};

class Quadrangle : public Triangle
{
public:
    int length_side_d;
    int value_angle_D;

    Quadrangle()
    {
        length_side_a = 10;
        length_side_b = 20;
        length_side_c = 30;
        length_side_d = 40;
        value_angle_A = 50;
        value_angle_B = 60;
        value_angle_C = 70;
        value_angle_D = 80;
        sides_count = 4;
        name = "Четырёхугольник:";
    }

    Quadrangle(int length_side_a, int length_side_b, int length_side_c, int length_side_d,
        int value_angle_A, int value_angle_B, int value_angle_C, int value_angle_D) : Quadrangle()
    {
        this->length_side_a = length_side_a;
        this->length_side_b = length_side_b;
        this->length_side_c = length_side_c;
        this->length_side_d = length_side_d;
        this->value_angle_A = value_angle_A;
        this->value_angle_B = value_angle_B;
        this->value_angle_C = value_angle_C;
        this->value_angle_D = value_angle_D;
    }

    int get_lenght_side_d()
    {
        return length_side_d;
    };

    int get_value_angle_D()
    {
        return value_angle_D;
    };

    bool check() override 
    {
        if ((sides_count == 4) && (value_angle_A + value_angle_B + value_angle_C + value_angle_D == 360))
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    void print_info() override 
    {
        Figure::print_info();
        std::cout << "Стороны:" << " a=" << get_lenght_side_a() << " b=" << get_lenght_side_b() << " c=" << get_lenght_side_c() <<
            " d=" << get_lenght_side_d() << std::endl;
        std::cout << "Углы:" << " А=" << get_value_angle_A() << " B=" << get_value_angle_B() << " C=" << get_value_angle_C() <<
            " D=" << get_value_angle_D() << std::endl << std::endl;
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram()
    {
        length_side_a = 20;
        length_side_b = 30;
        length_side_c = 20;
        length_side_d = 30;
        value_angle_A = 30;
        value_angle_B = 40;
        value_angle_C = 30;
        value_angle_D = 40;
        sides_count = 4;
        name = "Параллелограмм:";
    }

    Parallelogram(int length_side_a, int length_side_b,
        int value_angle_A, int value_angle_B) : Parallelogram()
    {
        this->length_side_a = length_side_a;
        this->length_side_b = length_side_b;
        length_side_c = length_side_a;
        length_side_d = length_side_b;
        this->value_angle_A = value_angle_A;
        this->value_angle_B = value_angle_B;
        value_angle_C = value_angle_A;
        value_angle_D = value_angle_B;
    }

    bool check() override 
    {
        if ((sides_count == 4) &&
            ((length_side_a == length_side_c) && (length_side_b == length_side_d)) &&
            ((value_angle_A == value_angle_C) && (value_angle_B == value_angle_D)) && (value_angle_A + value_angle_B + value_angle_C + value_angle_D == 360))
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};

class Rectangle1 : public Parallelogram
{
public:
    Rectangle1()
    {
        length_side_a = 10;
        length_side_b = 20;
        length_side_c = 10;
        length_side_d = 20;
        value_angle_A = 90;
        value_angle_B = 90;
        value_angle_C = 90;
        value_angle_D = 90;
        name = "Прямоугольник:";
    }

    Rectangle1(int length_side_a, int length_side_b) : Rectangle1()
    {
        this->length_side_a = length_side_a;
        length_side_b = length_side_b;
        length_side_c = length_side_a;
        length_side_d = length_side_b;
        this->value_angle_A = 90;
        value_angle_B = value_angle_A;
        value_angle_C = value_angle_B;
        value_angle_D = value_angle_C;
    }

    bool check() override 
    {
        if ((sides_count == 4) &&
            ((length_side_a == length_side_c) && (length_side_b == length_side_d)) &&
            ((value_angle_A == 90) && (value_angle_B == 90) && (value_angle_C == 90) && (value_angle_D == 90)))
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};

class Rhombus : public Parallelogram
{
public:
    Rhombus()
    {
        length_side_a = 30;
        length_side_b = 30;
        length_side_c = 30;
        length_side_d = 30;
        value_angle_A = 30;
        value_angle_B = 40;
        value_angle_C = 30;
        value_angle_D = 40;
        name = "Ромб:";
    }

    Rhombus(int length_side_a, int value_angle_A, int value_angle_B) : Rhombus()
    {
        this->length_side_a = length_side_a;
        length_side_b = length_side_a;
        length_side_c = length_side_b;
        length_side_d = length_side_c;
        this->value_angle_A = value_angle_A;
        this->value_angle_B = value_angle_B;
        value_angle_C = value_angle_A;
        value_angle_D = value_angle_B;
    }

    bool check() override 
    {
        if ((sides_count == 4) &&
            ((length_side_a == length_side_b) && (length_side_a == length_side_c) && (length_side_a == length_side_d)) &&
            ((value_angle_A == value_angle_C) && (value_angle_B == value_angle_D)) && (value_angle_A + value_angle_B + value_angle_C + value_angle_D == 360))
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};

class Square : public Quadrangle
{
public:
    Square()
    {
        length_side_a = 20;
        length_side_b = 20;
        length_side_c = 20;
        length_side_d = 20;
        value_angle_A = 90;
        value_angle_B = 90;
        value_angle_C = 90;
        value_angle_D = 90;
        name = "Квадрат:";
    }

    Square(int length_side_a) : Square()
    {
        this->length_side_a = length_side_a;
        length_side_b = length_side_a;
        length_side_c = length_side_b;
        length_side_d = length_side_c;
        value_angle_A = 90;
        value_angle_B = value_angle_A;
        value_angle_C = value_angle_B;
        value_angle_D = value_angle_C;
    }

    bool check() override 
    {
        if ((sides_count == 4) &&
            ((length_side_a == length_side_b) && (length_side_a == length_side_c) && (length_side_a == length_side_d)) &&
            ((value_angle_A == 90) && (value_angle_B = 90) && (value_angle_C == 90) && (value_angle_D == 90)))
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Figure f;
    Figure* par_f = &f;
    par_f->print_info();

    std::cout << std::endl;

    Triangle tr;
    Figure* par_tr = &tr;
    par_tr->print_info();
    
    Right_triangle rt1;
    Figure* par_rt1 = &rt1;
    par_rt1->print_info();
    
    Right_triangle rt2(10, 20, 30, 50, 40);
    Figure* par_rt2 = &rt2;
    par_rt2->print_info();

    Isosceles_triangle itr;
    Figure* par_itr = &itr;
    par_itr->print_info();

    Equilateral_triangle etr;
    Figure* par_etr = &etr;
    par_etr->print_info();

    Quadrangle qv;
    Figure* par_qv = &qv;
    par_qv->print_info();

    Rectangle1 rct;
    Figure* par_rct = &rct;
    par_rct->print_info();

    Square sq;
    Figure* par_sq = &sq;
    par_sq->print_info();

    Parallelogram prl;
    Figure* par_prl = &prl;
    par_prl->print_info();

    Rhombus rh;
    Figure* par_rh = &rh;
    par_rh->print_info();
}