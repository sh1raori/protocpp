#include <iostream>
#include <fstream>
#include "data.pb.h"

using namespace std;

void set_types(Types& types){
  // types.set_double_(1.1);
  types.set_float_(1.11);
  types.set_int32(1);
  types.set_int64(1);
  types.set_uint32(1);
  types.set_uint64(1);
  types.set_sint32(1);
  types.set_sint64(1);
  types.set_fixed32(1);
  types.set_fixed64(1);
  types.set_sfixed32(1);
  types.set_sfixed64(1);
  types.set_bool_(true);
  types.set_string("odin");
  types.set_bytes("1");
}

void set_mas(Mas& mas){
  for(int i = 0;i < 3;i++){
    mas.add_double_(1.1);
    mas.add_float_(1.11);
    mas.add_int32(1);
    mas.add_int64(1);
    mas.add_uint32(1);
    mas.add_uint64(1);
    mas.add_sint32(1);
    mas.add_sint64(1);
    mas.add_fixed32(1);
    mas.add_fixed64(1);
    mas.add_sfixed32(1);
    mas.add_sfixed64(1);
    mas.add_bool_(true);
    mas.add_string("odin");
    mas.add_bytes("1");
  }
}

void set_enum(Enum& enumm){
  enumm.set_status(Enum::THIRD);
}

void set_father(Father& father){
  Father::Daughter* daughter = father.add_daughter();
  daughter->set_name("Alisa");
}

void save_types(const char* fname, const Types& types){
	fstream out(fname, ios::out | ios::trunc | ios::binary);
	if(!types.SerializeToOstream(&out))
		throw runtime_error("failed sohr");
}

void load_types(const char* fname, Types& types){
	fstream in(fname, ios::in | ios::binary);
	if(!types.ParseFromIstream(&in))
		throw runtime_error("failed load");
}

void save_mas(const char* fname, const Mas& mas){
  fstream out(fname, ios::out | ios::trunc | ios::binary);
  if(!mas.SerializeToOstream(&out))
    throw runtime_error("failed sohr");
}

void load_mas(const char* fname, Mas& mas){
  fstream in(fname, ios::in | ios::binary);
  if(!mas.ParseFromIstream(&in))
    throw runtime_error("failed load");
}

void save_enum(const char* fname, const Enum& enumm){
  fstream out(fname, ios::out | ios::trunc | ios::binary);
  if(!enumm.SerializeToOstream(&out))
    throw runtime_error("failed sohr");
}

void load_enum(const char* fname, Enum& enumm){
  fstream in(fname, ios::in | ios::binary);
  if(!enumm.ParseFromIstream(&in))
    throw runtime_error("failed load");
}

void save_father(const char* fname, const Father& father){
  fstream out(fname, ios::out | ios::trunc | ios::binary);
  if(!father.SerializeToOstream(&out))
    throw runtime_error("failed sohr");
}

void load_father(const char* fname, Father& father){
  fstream in(fname, ios::in | ios::binary);
  if(!father.ParseFromIstream(&in))
    throw runtime_error("failed load");
}

void print_types(const Types& types){
	cout<<types.double_()<<" ";
	cout<<types.float_()<<" ";
	cout<<types.int32()<<" ";
  cout<<types.int64()<<" ";
  cout<<types.uint32()<<" ";
  cout<<types.uint64()<<" ";
  cout<<types.sint32()<<" ";
  cout<<types.sint64()<<" ";
  cout<<types.fixed32()<<" ";
  cout<<types.fixed64()<<" ";
  cout<<types.sfixed32()<<" ";
  cout<<types.sfixed64()<<" ";
  cout<<types.bool_()<<" ";
  cout<<types.string()<<" ";
  cout<<types.bytes()<<" ";
}

void print_mas(const Mas& mas){
  for(int j = 0;j<3;j++){
  cout<<mas.double_(j)<<" ";
  cout<<mas.float_(j)<<" ";
  cout<<mas.int32(j)<<" ";
  cout<<mas.int64(j)<<" ";
  cout<<mas.uint32(j)<<" ";
  cout<<mas.uint64(j)<<" ";
  cout<<mas.sint32(j)<<" ";
  cout<<mas.sint64(j)<<" ";
  cout<<mas.fixed32(j)<<" ";
  cout<<mas.fixed64(j)<<" ";
  cout<<mas.sfixed32(j)<<" ";
  cout<<mas.sfixed64(j)<<" ";
  cout<<mas.bool_(j)<<" ";
  cout<<mas.string(j)<<" ";
  cout<<mas.bytes(j)<<" ";
  cout<<endl;
  }
}

void print_enum(const Enum& enumm){
  switch (enumm.status()) {
        case Enum::FIRST:
          cout << "FIRST";
          break;
        case Enum::SECOND:
          cout << "SECOND";
          break;
        case Enum::THIRD:
          cout << "THIRD";
          break;
        default:
          cout << "Unknown";
          break;
      }
}

void print_father(const Father& father){
  const Father::Daughter& daughter = father.daughter(0);
  cout<<daughter.name();
}

int main(){
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	Types types;
  Mas mas;
  Enum enumm;
  Father father;

  // set_types(types);
  // set_mas(mas);
  // set_enum(enumm);
  set_father(father);

	// Types types1;
	// save_types("/home/shiro/test3/book.data", types);
	// load_types("/home/shiro/test3/book.data", types1);
 //  print_types(types1);

  // Mas mas1;
  // save_mas("/home/shiro/test3/book.data", mas);
  // load_mas("/home/shiro/test3/book.data", mas1);
  // print_mas(mas1);

  // Enum enumm1;
  // save_enum("/home/shiro/test3/book.data", enumm);
  // load_enum("/home/shiro/test3/book.data", enumm1);
  // print_enum(enumm1);

  Father father1;
  save_father("/home/shiro/test3/book.data", father);
  load_father("/home/shiro/test3/book.data", father1);
  print_father(father1);
}