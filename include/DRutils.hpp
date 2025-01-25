// DEFAULT RAYLIB UTILS

#pragma once


#include <algorithm>
#include <array>
#include <limits>
#include <raylib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <sys/stat.h>


////// RAYLIB VECTOR OPERATOR OVERLOADING //////
    inline Vector2 operator + (const Vector2& v1, const Vector2& v2)    { return { v1.x + v2.x, v1.y + v2.y }; }
    inline Vector2 operator - (const Vector2& v1, const Vector2& v2)    { return { v1.x - v2.x, v1.y - v2.y }; }
    inline Vector2 operator * (const float& f, const Vector2& v1)       { return { v1.x * f, v1.y * f };       }
    inline Vector2 operator * (const Vector2& v1, const float& f)       { return { v1.x * f, v1.y * f };       }
    inline Vector2 operator / (const Vector2& v1, const Vector2& v2)    { return { v1.x / v2.x, v1.y / v2.y }; }
    inline Vector2 operator / (const Vector2& v1, const float& f)       { return { v1.x / f, v1.y / f };       }
    inline void operator += (Vector2& v1, const Vector2& v2)            { v1.x += v2.x; v1.y += v2.y;          }
    inline void operator -= (Vector2& v1, const Vector2& v2)            { v1.x -= v2.x; v1.y -= v2.y;          }
    inline void operator *= (Vector2& v1, const float& f)               { v1.x *= f; v1.y *= f;                }
    inline void operator /= (Vector2& v1, const float& f)               { v1.x /= f; v1.y /= f;                }
    inline void operator << (std::ostream& stream, const Vector2& v)    { stream << v.x << " " << v.y;         }
    inline bool operator == (const Vector2& v1, const Vector2& v2)      { return v1.x == v2.x && v1.y == v2.y; }

    inline Vector3 operator + (const Vector3& v1, const Vector3& v2)    { return { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };    }
    inline Vector3 operator - (const Vector3& v1, const Vector3& v2)    { return { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };    }
    inline Vector3 operator * (const float& f, const Vector3& v1)       { return { v1.x * f, v1.y * f, v1.z * f };             }
    inline Vector3 operator * (const Vector3& v1, const float& f)       { return { v1.x * f, v1.y * f, v1.z * f };             }
    inline Vector3 operator / (const Vector3& v1, const Vector3& v2)    { return { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z };    }
    inline Vector3 operator / (const Vector3& v1, const float& f)       { return { v1.x / f, v1.y / f, v1.z / f };             }
    inline void operator += (Vector3& v1, const Vector3& v2)            { v1.x += v2.x; v1.y += v2.y; v1.z += v2.z;            }
    inline void operator -= (Vector3& v1, const Vector3& v2)            { v1.x -= v2.x; v1.y -= v2.y; v1.z -= v2.z;            }
    inline void operator *= (Vector3& v1, const float& f)               { v1.x *= f; v1.y *= f; v1.z *= f;                     }
    inline void operator /= (Vector3& v1, const float& f)               { v1.x /= f; v1.y /= f; v1.z /= f;                     }
    inline void operator << (std::ostream& stream, const Vector3& v)    { stream << v.x << " " << v.y << " " << v.z;           }
    inline bool operator == (const Vector3& v1, const Vector3& v2)      { return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z; }

    inline bool operator == (const Color& c1, const Color& c2)      { return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a; }
    inline void operator << (std::ostream& stream, const Color& v) {
        stream << static_cast<int>(v.r) << " "
               << static_cast<int>(v.g) << " "
               << static_cast<int>(v.b) << " "
               << static_cast<int>(v.a);
    }


////// DEBUG UTILS //////
    template <typename T>
    inline void DEB(T& m) { std::cout << m << "\n"; }
    inline void DEB(Vector2& m) { std::cout << m.x << " " << m.y << "\n"; }
    inline void DEB(Vector3& m) { std::cout << m.x << " " << m.y << " " << m.z << "\n"; }

////// NAMESPACE UTILS //////
namespace utils {
    ////// MATH //////
        inline float square(const float& f)                             { return f * f; }
        inline float cube(const float& f)                               { return f * f * f; }

        inline float dot(const Vector2& v1, const Vector2& v2)          { return v1.x * v2.x + v1.y * v2.y;               }
        inline float length(const Vector2& v)                           { return std::sqrt(utils::dot(v, v));             }
        inline float distance(const Vector2& v1, const Vector2& v2)     { return std::sqrt(utils::dot(v1 - v2, v1 - v2)); }
        inline Vector2 normalize(const Vector2& v)                      { return v / utils::length(v);                    }

        inline float dot(const Vector3& v1, const Vector3& v2)          { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
        inline float length(const Vector3& v)                           { return std::sqrt(utils::dot(v, v));             }
        inline float distance(const Vector3& v1, const Vector3& v2)     { return std::sqrt(utils::dot(v1 - v2, v1 - v2)); }
        inline Vector3 normalize(const Vector3& v)                      { return v / utils::length(v);                    }

    ////// OTHER //////
        inline bool file_exists(const std::string PATH) {
              struct stat buffer;   
              return (stat (PATH.c_str(), &buffer) == 0); 
        }

        inline float random_num(const float& min, const float& max) {
            const double random = ((double) rand() / (RAND_MAX));
            const double range = max - min;
            return (random * range + min);
        }

        inline Vector2 random_vec2(const Vector2& min, const Vector2& max) {
            return {
                utils::random_num(min.x, max.x),
                utils::random_num(min.y, max.y)
            };
        } inline Vector3 random_vec3(const Vector3& min, const Vector3& max) {
            return {
                utils::random_num(min.x, max.x),
                utils::random_num(min.y, max.y),
                utils::random_num(min.z, max.z)
            };
        } inline std::vector<float> random_vec(const float& vec_length, const float& min, const float& max) {
            std::vector<float> ret;
            for (int i = 0; i < vec_length; i++) { ret.push_back(random_num(min, max)); }
            return ret;
        }

        inline void progress_bar(const std::string& description, const float& value, const float& max_value, const int& bar_length) {
            double percentage = static_cast<double>(value) / max_value;
            int pos = static_cast<int>(bar_length * percentage);

            std::cout << description << ": [";
            for (int i = 0; i < bar_length; ++i) {
                if (i < pos) std::cout << "#";
                else std::cout << "-";
            }
            std::cout << "] " << std::fixed << std::setprecision(2) << percentage * 100.0 << "%\r";
            std::cout.flush();

            if (value / max_value == 1.0f) std::cout << "\n";
        }

    ////// PROJECT SPECIFIC //////

}
