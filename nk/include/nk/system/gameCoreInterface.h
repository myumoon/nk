//=============================================================================
/*!	@file	gameCoreIntercafe.h

	@brief	ゲームコア

	@author	ryunosuke ide
	@date	2014.08.11
*/
//=============================================================================

#ifndef NK_GAME_CORE_INTERFACE_H
#define NK_GAME_CORE_INTERFACE_H


namespace nk {
namespace system {


//=============================================================================
/*!	@brief	ゲームコア
*/
//=============================================================================
class GameCoreInterface {
public:
	
	//! デストラクタ
	virtual ~GameCoreInterface() {}

	//===========================================================================
	/*!	@brief		更新
	*/
	//===========================================================================
	virtual void	Update() = 0;

};

	
}	// namespace system
}	// namespace nk





#endif  // NK_GAME_CORE_INTERFACE_H
