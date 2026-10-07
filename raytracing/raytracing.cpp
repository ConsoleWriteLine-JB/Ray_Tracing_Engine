#include <iostream>
#include <cmath>

struct vec3 {
public:
    float x, y, z;

    vec3(float a, float b, float c) : x(a), y(b), z(c) {}

    vec3 Sub(const vec3& other_vec) const {
        float t_x, t_y, t_z;

        t_x = x - other_vec.x;
        t_y = y - other_vec.y;
        t_z = z - other_vec.z;

        return vec3(t_x, t_y, t_z);
    }

    vec3 Add(const vec3& other_vec) const {
        float t_x, t_y, t_z;

        t_x = x + other_vec.x;
        t_y = y + other_vec.y;
        t_z = z + other_vec.z;

        return vec3(t_x, t_y, t_z);
    }

    vec3 Mult(float num) const {
        float t_x, t_y, t_z;

        t_x = x * num;
        t_y = y * num;
        t_z = z * num;

        return vec3(t_x, t_y, t_z);
    }

    float Dot(const vec3& other_vec) const {
        float t_x, t_y, t_z;

        t_x = x * other_vec.x;
        t_y = y * other_vec.y;
        t_z = z * other_vec.z;

        return (t_x + t_y + t_z);
    }

    vec3 Cross(const vec3& other_vec) const {
        float t_x, t_y, t_z;

        t_x = (y * other_vec.z) - (z * other_vec.y);
        t_y = (z * other_vec.x) - (x * other_vec.z);
        t_z = (x * other_vec.y) - (y * other_vec.x);

        return vec3(t_x, t_y, t_z);
    }

    float Len() const {
        return (std::sqrt(((x * x) + (y * y) + (z * z))));
    }

    vec3 Norm() const {
        float length = Len();
        return vec3(x / length, y / length, z / length);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}