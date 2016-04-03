/*! \file Constant.h
 *  \brief Defines some constants to be used later on
 */
#ifndef HEAD_CONSTANT
#define HEAD_CONSTANT
#include <SFML/Window.hpp>

extern const double pi; //!< Aera of a disk of radius 1
extern const double gravity; //!< Accelaration of a body in fall without friction
extern const int pixel_per_meter; //!< How much one needs to multiply a meter to have it in pixel

extern const sf::Keyboard::Key key_jump; /*!< The key to press in order to jump*/
extern const sf::Keyboard::Key key_roll; /*!< The key to press in order to roll*/
extern const sf::Keyboard::Key key_focus; /*!< The key to press in order to focus*/
extern const sf::Keyboard::Key key_dash; /*!< The key to press in order to dash*/
#endif //HEAD_CONSTANT
