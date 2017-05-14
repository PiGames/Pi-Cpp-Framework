template<class T, class ...Args>
inline typename std::enable_if<std::is_base_of<SubState, T>::value>::type
State::addSubState( uint8_t id, Args&& ...args )
{
#if defined _DEBUG // We don't need this check - Release won't have this type of bugs. Seriously. 
	if ( this->hasSubState( id ) )
	{
		Logger::Log( "Cannot add SubState, found same ID: " + std::to_string( id ), Logger::BOTH, Logger::ERROR );
		return;
	}
#endif
	DEBUG_LOG( "Added SubState: " + std::to_string( id ), Logger::BOTH, Logger::INFO );
	this->subStates.insert( std::make_pair( id, std::make_unique<T>( std::forward<Args>( args )... ) ) );
}