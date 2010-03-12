
#ifndef SASL_ENUMS_SYNTAX_NODE_TYPES_H
#define SASL_ENUMS_SYNTAX_NODE_TYPES_H

#include "../enums/enum_base.h" 

struct syntax_node_types :
	public enum_base< syntax_node_types, uint64_t >
	, bitwise_op< syntax_node_types >, equal_op< syntax_node_types >, value_op< syntax_node_types, uint64_t >
{
	friend struct enum_hasher;
private:
	syntax_node_types( const storage_type& val ): base_type( val ){}
	
public:
	syntax_node_types( const this_type& rhs )
		:base_type(rhs.val_)
	{}
	
	this_type& operator = ( const this_type& rhs){
		val_ = rhs.val_;
		return *this;
	}

	const static this_type expression_statement;
	const static this_type member_expression;
	const static this_type unary_expression;
	const static this_type for_statement;
	const static this_type initializer;
	const static this_type function_type;
	const static this_type variable_declaration;
	const static this_type cond_expression;
	const static this_type type_specifier;
	const static this_type compound_statement;
	const static this_type typedef_definition;
	const static this_type struct_type;
	const static this_type while_statement;
	const static this_type switch_statement;
	const static this_type statement;
	const static this_type cast_expression;
	const static this_type if_statement;
	const static this_type constant_expression;
	const static this_type node;
	const static this_type quanlified_type;
	const static this_type dowhile_statement;
	const static this_type declaration;
	const static this_type array_type;
	const static this_type jump_statement;
	const static this_type buildin_type;
	const static this_type binary_expression;
	const static this_type expression_list;
	const static this_type member_initializer;
	const static this_type declaration_statement;
	const static this_type index_expression;
	const static this_type expression_initializer;
	const static this_type expression;
	const static this_type call_expression;


	static std::string to_name( const this_type& enum_val );
	static this_type from_name( const std::string& name );

};
#endif