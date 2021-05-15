#ifndef		SERIALIZER_HPP
#define		SERIALIZER_HPP

#include	<iostream>
#include	"Error.hpp"

class Serializer{
	static constexpr char Separator = ' ';
	std::ostream& out_;
public:
	explicit Serializer( std::ostream& out ) : out_(out){}
	template <class T>
	Error save( T& object ){

		return object.serialize(*this);
	}

	template <class... ArgsT>
	Error operator()( ArgsT&... args ){

		return process(args...);
	}

	template <class T, class... ArgsT>
	Error process( T& t, ArgsT&... args ){

		one_to_stream(t);
		return process(args...);
	}

	template <class T>
	Error process( T& t ){

		return one_to_stream(t);
	}

	Error one_to_stream( bool& var ) const {

		if( var )
			out_ << "true" << Separator;
		else
			out_ << "false" << Separator;
		return Error::NoError;
	}

	Error one_to_stream( uint64_t& var ) const {

		out_ << var << Separator;
		return Error::NoError;
	}
};

#endif