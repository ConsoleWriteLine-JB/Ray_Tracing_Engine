#include <iostream>
#include <cmath>
#include <fstream>

struct vec3 {
public:
    float x, y, z;

    vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    vec3() : x(0), y(0), z(0) {}

    vec3 Sub(const vec3& other_vec) const {
        //Subtracts vectors
        float t_x, t_y, t_z;

        t_x = x - other_vec.x;
        t_y = y - other_vec.y;
        t_z = z - other_vec.z;

        return vec3(t_x, t_y, t_z);
    }

    vec3 Add(const vec3& other_vec) const {
        //Adds vectors
        float t_x, t_y, t_z;

        t_x = x + other_vec.x;
        t_y = y + other_vec.y;
        t_z = z + other_vec.z;

        return vec3(t_x, t_y, t_z);
    }

    vec3 Mult(float num) const {
        //Multiplies vector by a scalar number
        float t_x, t_y, t_z;

        t_x = x * num;
        t_y = y * num;
        t_z = z * num;

        return vec3(t_x, t_y, t_z);
    }

    float Dot(const vec3& other_vec) const {
        // Dot product of 2 vectors
        float t_x, t_y, t_z;

        t_x = x * other_vec.x;
        t_y = y * other_vec.y;
        t_z = z * other_vec.z;

        return (t_x + t_y + t_z);
    }

    vec3 Cross(const vec3& other_vec) const {
        //Cross multiplication of 2 vectors
        float t_x, t_y, t_z;

        t_x = (y * other_vec.z) - (z * other_vec.y);
        t_y = (z * other_vec.x) - (x * other_vec.z);
        t_z = (x * other_vec.y) - (y * other_vec.x);

        return vec3(t_x, t_y, t_z);
    }

    float Len() const {
        //Calculates the length of a vector
        return (std::sqrt(((x * x) + (y * y) + (z * z))));
    }

    vec3 Norm() const {
        //Calculates the Norm of the vector
        float length = Len();
        return vec3(x / length, y / length, z / length);
    }
};

struct Ray {
    vec3 origin;
    vec3 direction;

    Ray(const vec3& o, const vec3& d) : origin(o), direction(d) {}

    vec3 at(float t) {
        //Creates the light ray
        vec3 holder = direction.Mult(t);
        holder = holder.Add(origin);
        return holder;
    };
};

int main()
{
    int img_width = 800;
    int img_height = 600;

    //Positition of the virtual camera
    vec3 Cam(0, 0, 0);

    //Creates the image file
    std::ofstream outfile("image.ppm");

    //Adds the neccissary image headers so that the image is the correct size and so that it is color.
    outfile << "P3\n" << img_width << " " << img_height << "\n255\n";

    for (int j = img_height - 1; j >= 0; j--) {
        for (int i = 0; i < img_width; i++) {
            // Calculate the color based on the pixel position
            // Write colors to output file
        }
    }
    outfile.close();
}