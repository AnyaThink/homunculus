#ifndef RENDERER_H
#define RENDERER_H
#include "common/err_t.h"
#include "engine/renderer/font.h"

class engine_t;
class gui_system_t;
class shader_t;

namespace sf
{
  class RenderWindow;
}

class renderer_t
{
  engine_t &m_engine;
  sf::RenderWindow &m_window;
  gui_system_t &m_gui;
  font_t m_font;
  unique_ptr<shader_t> m_text_shader;
public:
  renderer_t (engine_t &engine);
  err_t init ();
  void render ();
  void render_text (const string &text, glm::vec2 &pos, glm::vec3 &color);
  font_t &get_font () {return m_font;}
  shader_t *get_text_shader () {return m_text_shader.get ();}
};

#endif // RENDERER_H
