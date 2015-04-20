//=============================================================================
/*!	@file	gameCoreIntercafe.h

	@brief	�Q�[���R�A

	@author	ryunosuke ide
	@date	2014.08.11
*/
//=============================================================================

#ifndef NK_GAME_CORE_INTERFACE_H
#define NK_GAME_CORE_INTERFACE_H


namespace nk {
namespace system {


//=============================================================================
/*!	@brief	�Q�[���R�A
*/
//=============================================================================
class GameCoreInterface {
public:
	
	//! �f�X�g���N�^
	virtual ~GameCoreInterface() {}

	//===========================================================================
	/*!	@brief		�X�V
	*/
	//===========================================================================
	virtual void	Update() = 0;

};

	
}	// namespace system
}	// namespace nk





#endif  // NK_GAME_CORE_INTERFACE_H
