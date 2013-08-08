#ifndef UTILS_H
#define UTILS_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <Box2D/Common/b2Math.h>


namespace util
{
	const float SCALE = 32.f; // 1m = 32px - used to scale box2D's MKS units to pixels
	const float UNSCALE = 1/SCALE; // 32px = 1m - reciprocal to scale, used to downscale pixels to MKS
	const float DEGTORAD = 0.017453f; // PI / 180 - converts an angle in degrees to radians
	const float RADTODEG = 57.29577f; // 180 / PI - converts an angle in radians to degrees

	// Converts SFML's Vector2 object to Box2D's b2Vec2
	//shouldDownScale - if true it scales the values from pixels to MKS using UNSCALE constant
	template <typename T>
	b2Vec2 SFtoB2(const sf::Vector2<T>& vect, bool shouldDownScale = true)
	{
		if(shouldDownScale)
			return b2Vec2(static_cast<float32>(vect.x * UNSCALE), static_cast<float32>(vect.y * UNSCALE));
		else
			return b2Vec2(static_cast<float32>(vect.x), static_cast<float32>(vect.y));
	}

	// Converts Box2D's b2Vec2 object to SFML's Vector2
	//shouldUpScale - if true it scales the values from MKS to pixels using SCALE constant
	template <typename T>
	sf::Vector2<T> B2toSF(const b2Vec2& vect, bool shouldUpScale = true)
	{
		if(shouldUpScale)
			return sf::Vector2<T>(static_cast<T>(vect.x * SCALE), static_cast<T>(vect.y * SCALE));
		else
			return sf::Vector2<T>(static_cast<T>(vect.x), static_cast<T>(vect.y));
	}

	// Converts degrees to radians
	float32 degToRad(float deg);

	// Converts radians to degrees
	float radToDeg(float rad);

	const sf::Uint8 SF_COLOR_MAX = 255;
	const sf::Uint8 SF_COLOR_MIN = 0;

	//Sets the alpha value of a drawable SFML object
	template<typename T>
	void setAlpha(T& object, sf::Uint8 alpha)
	{
		sf::Color objectColor = object.getColor();
		objectColor.a = alpha;
		object.setColor(objectColor);
	}

	//Retrieves the alpha of a drawable SFML object
	template<typename T>
	sf::Uint8 getAlpha(T& object)
	{
		return object.getColor().a;
	}
}
#endif // UTILS_H
