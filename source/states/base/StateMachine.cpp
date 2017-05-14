#include "StateMachine.hpp"

namespace pi
{
	std::unique_ptr<State> StateMachine::createState( uint8_t id )
	{
		auto result = this->factories.find( id );

		// There is no states registered / cannot find state of that id
		assert( !( result == this->factories.end() ) );

		return std::move( result->second() );
	}

	void StateMachine::Run()
	{
		uint8_t nextState = this->actualState;

		while ( this->actualState != 0 )
		{
			this->stack[actualState] = std::move( this->createState( this->actualState ) );

			this->stack[actualState]->OnStart();
			nextState = this->stack[actualState]->Run();
			this->stack[actualState]->OnStop();

			this->actualState = nextState;
		}
	}
}