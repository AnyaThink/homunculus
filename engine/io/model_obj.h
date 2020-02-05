#ifndef MODEL_OBJ_H
#define MODEL_OBJ_H
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>
#include "common/err_t.h"


/// @brief Class to import .obj model format
/// @details
/// .obj model format can be used for static not-animated meshes
class model_obj_t
{
  vector<glm::vec3> m_vertices;
  vector<glm::vec3> m_normals;
  vector<glm::vec2> m_uv;
  vector<glm::uvec3> m_vertex_indices;
  vector<glm::uvec3> m_uv_indices;
  vector<glm::uvec3> m_normal_indices;
private:
  err_t parse_position_3d (stringstream &ss, vector<glm::vec3> &vec);
  err_t parse_vertex_line (stringstream &ss);
  err_t parse_vertex_texture_coordinate_line (stringstream &ss);
  err_t parse_vertex_normal_line (stringstream &ss);
  err_t parse_face_line (stringstream &ss);
public:
  model_obj_t () = default;
  model_obj_t (const string &filename);
  err_t load (const string &filename);
};

#endif // MODEL_OBJ_H
