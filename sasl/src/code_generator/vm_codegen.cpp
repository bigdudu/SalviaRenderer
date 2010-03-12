#include "../../include/code_generator/vm_codegen.h"

using namespace boost;

BEGIN_NS_SASL_CODE_GENERATOR()

shared_ptr<vm_codegen::storage_t> vm_codegen::create_storage( storage_mode mode, vm_codegen::address_t addr ){
	return shared_ptr<vm_codegen::storage_t>( new vm_codegen::storage_t(mode, addr), storage_deleter(*this) );	
}

void vm_codegen::_save_r( vm::regid_t reg_id )
{
	//free_reg( reg_id );
	//mcgen_._push( reg_id );
}

void vm_codegen::_restore_r( vm::regid_t reg_id )
{
	//reallocate_reg( reg_id );
	//mcgen_._pop( reg_id );
}

vm::regid_t vm_codegen::allocate_reg()
{
	for( vm::regid_t id = 0; id < vm::regid_t(vm::i_register_count); ++id ){
		if ( !reg_usage.test(id) ){
			reallocate_reg( id );
			return id;
		}
	}
	assert(false);
	return -1;
}

vm_codegen& vm_codegen::free_reg( vm::regid_t reg_id )
{
	assert( reg_usage.test( reg_id ) );
	reg_usage.set( reg_id, false );
	return *this;
}

void vm_codegen::free_storage( storage_t& s )
{
	if ( s.mode == storage_mode::register_id ){
		free_reg( s.addr );
	}
}


const std::vector<instruction>& vm_codegen::codes()
{
	return mcgen_.codes();
}

vm_codegen& vm_codegen::reallocate_reg( vm::regid_t reg_id )
{
	assert( !reg_usage.test(reg_id) );
	reg_usage.set( reg_id, true );
	return *this;
}

vm_codegen::vm_codegen() : reg_usage(0){
}

void vm_codegen::storage_deleter::operator()( storage_t* p )
{
	if(p == NULL) return;
	vm.free_storage(*p);
	delete p;
}

END_NS_SASL_CODE_GENERATOR()