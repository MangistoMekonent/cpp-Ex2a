/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Ohad Maday>
 * 
 * Date: 2020-03
 */

#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;

TEST_CASE("Add empty words") {
    family::Tree T = {"name"};
    CHECK_THROWS_AS(T.setName(" YAKOB"), std::exception);
    CHECK_THROWS_AS(T.setName("Y AKOB"), std::exception);
    CHECK_THROWS_AS(T.setName("YA KOB"), std::exception);
    CHECK_THROWS_AS(T.setName("YAK OB"), std::exception);
    CHECK_THROWS_AS(T.setName("YAKO B"), std::exception);
    CHECK_THROWS_AS(T.setName("YAKOB "), std::exception);
    CHECK_THROWS_AS(T.setName("  YAKOB  "), std::exception);
    CHECK_THROWS_AS(T.setName(" Y AK O B"), std::exception);
    CHECK_THROWS_AS(T.setName(" Y A K O B "), std::exception);
    CHECK_THROWS_AS(T.setName(" "), std::exception);
    CHECK_THROWS_AS(T.setName("   "), std::exception);
    CHECK_THROWS_AS(T.setName("              "), std::exception);
    CHECK_THROWS_AS(T.setName(""), std::exception);

    
}


TEST_CASE("Add empty words") {
family::Tree T (" "); // Yosef is the "root" of the tree (the youngest person).
	CHECK_THROWS_AS(T.addFather(" ", "Yaakov"), std::exception);   // Tells the tree that the father of Yosef is Yaakov.
	CHECK_THROWS_AS(T.addMother(" ", "Rachel"), std::exception);  // Tells the tree that the mother of Yosef is Rachel.
	CHECK_THROWS_AS(T.addFather("Yaakov", " "), std::exception);
    CHECK_THROWS_AS(T.addMother("Yaakov", " "), std::exception);

}
TEST_CASE("Add a space before names") {
family::Tree T (" Yaakov"); // Yosef is the "root" of the tree (the youngest person).
	CHECK_THROWS_AS(T.addFather(" Yaakov", "Yaakov"), std::exception);  // Tells the tree that the father of Yosef is Yaakov.
	CHECK_THROWS_AS(T.addMother(" Yaakov", " Rachel"), std::exception);   // Tells the tree that the mother of Yosef is Rachel.
	CHECK_THROWS_AS(T.addFather(" Yaakov", "  Yaakov"), std::exception);
    CHECK_THROWS_AS(T.addMother(" Yaakov", "      SHIFRA"), std::exception);
}

TEST_CASE("Add many spaces") {
    family::Tree T (" Yaa    kov    "); // Yosef is the "root" of the tree (the youngest person).
    CHECK_THROWS_AS(T.addFather(" Yaa    kov    ", "Yaakov"), std::exception);   // Tells the tree that the father of Yosef is Yaakov.
	CHECK_THROWS_AS(T.addMother("Yaakov", " Yaa    kov    "), std::exception);   // Tells the tree that the mother of Yosef is Rachel.
	CHECK_THROWS_AS(T.addFather(" Yaa    kov    ", " JA KUB    "), std::exception);
    CHECK_THROWS_AS(T.addMother(" JA KUB    ", "      SH  I F  R A    "), std::exception);
}

TEST_CASE("Relations") {
	family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah")
     .addMother("Terah", "Rivka")
     .addMother("Rivka", "Chaya");
    
    CHECK(T.relation("Rivka") == string("mother"));
    CHECK(T.relation("Terah") == string("great-great-grandfather"));
    CHECK(T.relation("xyz") == string("unrelated"));
    CHECK(T.relation("Avraham") == string("great-grandfather"));
    CHECK(T.relation("Terah") != string("unrelated"));
    CHECK(T.relation("xyz") != string("mother"));
    CHECK(T.relation("Chaya") == string("grandmother"));
    CHECK(T.relation(" ") != string("unrelated"));
    CHECK(T.relation("Elad") == string("unrelated"));
    CHECK(T.relation("Shlomi") == string("unrelated"));
    CHECK(T.relation("Yoram") == string("unrelated"));
    CHECK(T.relation("Rachel") == string("mother"));
}

TEST_CASE("Relations and find") {
	family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah")
     .addMother("Terah", "Rivka")
     .addMother("Rivka", "Chaya");
    
    CHECK(T.relation("rivka") == string("mother"));
    CHECK(T.relation("Rivka") == string("mother"));
    CHECK(T.relation("RIVKA") == string("mother"));
    CHECK(T.relation("RiVkA") == string("mother"));
    CHECK(T.relation("RivkA") == string("mother"));
    CHECK(T.relation("terah") == string("great-great-grandfather"));
    CHECK(T.relation("Terah") == string("great-great-grandfather"));
    CHECK(T.relation("TeRaH") == string("great-great-grandfather"));
    CHECK(T.relation("TERAH") == string("great-great-grandfather"));
    CHECK(T.relation("xyz") == string("unrelated"));
    CHECK(T.relation("avraham") == string("great-grandfather"));
    CHECK(T.relation("Avraham") == string("great-grandfather"));
    CHECK(T.relation("AvRaHaM") == string("great-grandfather"));
    CHECK(T.relation("AVRAHAM") == string("great-grandfather"));
    CHECK(T.relation("chaya") == string("grandmother"));
    CHECK(T.relation("Chaya") == string("grandmother"));
    CHECK(T.relation("ChAyA") == string("grandmother"));
    CHECK(T.relation("CHAYA") == string("grandmother"));
    CHECK(T.relation("Elad") == string("unrelated"));
    CHECK(T.relation("Shlomi") == string("unrelated"));
    CHECK(T.relation("Yoram") == string("unrelated"));
    CHECK(T.relation("rachel") == string("mother"));
    CHECK(T.relation("Rachel") == string("mother"));
    CHECK(T.relation("RaChEl") == string("mother"));
    CHECK(T.relation("RACHEL") == string("mother"));
    
    
    CHECK_THROWS_AS(T.find("-M-O-T-H-E-R-"), std::exception());
    CHECK_THROWS_AS(T.find(" mother"), std::exception());
    CHECK_THROWS_AS(T.find("m other"), std::exception());
    CHECK_THROWS_AS(T.find("mo ther"), std::exception());
    CHECK_THROWS_AS(T.find("mot her"), std::exception());
    CHECK_THROWS_AS(T.find("moth er"), std::exception());
    CHECK_THROWS_AS(T.find("mothe r"), std::exception());
    CHECK_THROWS_AS(T.find("mother "), std::exception());
    CHECK_THROWS_AS(T.find("m-other"), std::exception());
    CHECK_THROWS_AS(T.find("-mother"), std::exception());
    CHECK_THROWS_AS(T.find("-mother-"), std::exception());
    CHECK_THROWS_AS(T.find("m-o-ther"), std::exception());
    CHECK_THROWS_AS(T.find("-mo-ther"), std::exception());
    CHECK_THROWS_AS(T.find("-mot-her-"), std::exception());
    CHECK_THROWS_AS(T.find(" mo-the-r"), std::exception());
    CHECK_THROWS_AS(T.find("-mot he-r"), std::exception());
    CHECK_THROWS_AS(T.find("-mo -ther-"), std::exception());
    
    CHECK(T.find("mOtHeR") == string("Rivka"));
    CHECK(T.find("mother") == string("Rivka"));
    CHECK(T.find("great-great-grandfather") == string("Terah"));
    CHECK(T.find("mother") == string("Rachel"));
    CHECK(string("Chaya") == T.find("grandmother"));
    CHECK(string("Avraham") == T.find("great-grandfather"));
    CHECK(string("Rivka") == T.find("mother"));
    CHECK(string("Terah") == T.find("great-great-grandfather"));
     
}

TEST_CASE("Remove") {
	family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah")
     .addMother("Terah", "Rivka")
     .addMother("Rivka", "Chaya");
    
    T.remove("Rivka");
    CHECK(T.relation("Rivka") == string("unrelated"));
    CHECK(T.relation("Chaya") == string("unrelated"));
    CHECK_THROWS_AS(T.remove(" "), std::exception());
    CHECK_THROWS_AS(T.remove("xyz"), std::exception());
    T.remove("Yaakov");
    CHECK(T.find("father") != string("Yaakov"));
    CHECK(T.relation("Yaakov") == string("unrelated"));
    CHECK(T.relation("Isaac") == string("unrelated"));
    CHECK(T.find("grandfather") != string("Isaac"));
    CHECK(T.relation("Chaya") == string("unrelated"));
    CHECK(T.find("mother") != string("Chaya"));
    CHECK(T.relation("Rivka") == string("unrelated"));
    CHECK(T.find("mother") != string("Rivka"));
    CHECK(T.relation("Avraham") == string("unrelated"));
    CHECK(T.find("father") != string("Avraham"));
    CHECK(T.relation("Terah") == string("unrelated")); 
    CHECK(T.find("great-great-grandfather") != string("Terah"));
    CHECK(T.find("Terah") == string("unrelated"));
    CHECK(string("Avraham") != T.find("great-grandfather"));

}

TEST_CASE("Name changed")
{
    	family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah")
     .addMother("Terah", "Rivka")
     .addMother("Rivka", "Chaya");
    
    T.addFather("Yosef","Moshe");
    CHECK(T.relation("Moshe") == string("father"));
    CHECK(T.relation("Yaakov") == string("unrelated"));
    T.remove("Chaya");
    CHECK(T.relation("Chaya") == string("unrelated"));
    T.remove("Rivka");
    CHECK(T.relation("Rivka") == string("unrelated"));
    T.remove("Terah");
    CHECK(T.relation("Terah") == string("unrelated"));
    T.remove("Avraham");
    CHECK(T.relation("Avraham") == string("unrelated"));
    T.remove("Isaac");
    CHECK(T.relation("Isaac") == string("unrelated"));
    T.remove("Moshe");
    CHECK(T.relation("Moshe") == string("unrelated"));
    T.remove("Rachel");
    CHECK(T.relation("Rachel") == string("unrelated"));



}