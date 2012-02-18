#ifndef TILESET_HPP
#define TILESET_HPP

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <GGE/Core/App.hpp>
#include <GGE/Core/tmx/tmx.hpp>

namespace GGE
{

class Tileset
{
public:
	Tileset();
	~Tileset();

	/**
	 * Registers the application described by theApp.
	 * 
	 * @param [in,out]	theApp	If non-null, the application.
	 */
	void RegisterApp(App* theApp);

	/**
	 * Inicializa el tileset.
	 *
	 * @param [in,out]	TheTmx	Puntero al archivo tmx.
	 */
	void Init(TmxMap* TheTmx);

	/**
	 * Dibuja un tile en pantalla
	 *
	 * @param	theIndx	el indice del tile que se quiere dibujar.
	 * @param	thePos 	Vector con la posici�n en la que se dibujar�.
	 */
	void Draw(int theIndx, sf::Vector2i thePos);

private:
	/// Puntero a APP
	App* mApp;
	/// Vector que contiene las im�genes
	std::vector<sf::Sprite*> mImages;
	/// Vector que contiene el n�mero del primer tile del tileset
	std::vector<int> mFirstgid;
	/// Vector que contiene los rets de los tilesets
	std::vector<sf::IntRect> mRects;

	/**
	 * Devuelve el tileset al que pertenece un tile en concreto.
	 *
	 * @param	theIndx	the indx.
	 *
	 * @return	The number tileset.
	 */
	int GetNumTileset(int theIndx) const;


}; // Class Tileset

} // Namespace GGE

#endif // TILESET_HPP