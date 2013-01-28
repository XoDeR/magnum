/*
    Copyright © 2010, 2011, 2012 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include <sstream>
#include <TestSuite/Tester.h>
#include <Utility/Configuration.h>

#include "Mesh.h"

namespace Magnum { namespace Test {

class MeshTest: public Corrade::TestSuite::Tester {
    public:
        MeshTest();

        void debugPrimitive();
        void debugIndexType();
        void configurationPrimitive();
        void configurationIndexType();
};

MeshTest::MeshTest() {
    addTests(&MeshTest::debugPrimitive,
             &MeshTest::debugIndexType,
             &MeshTest::configurationPrimitive,
             &MeshTest::configurationIndexType);
}

void MeshTest::debugPrimitive() {
    std::ostringstream o;
    Debug(&o) << Mesh::Primitive::TriangleFan;
    CORRADE_COMPARE(o.str(), "Mesh::Primitive::TriangleFan\n");
}

void MeshTest::debugIndexType() {
    std::ostringstream o;
    Debug(&o) << Mesh::IndexType::UnsignedShort;
    CORRADE_COMPARE(o.str(), "Mesh::IndexType::UnsignedShort\n");
}

void MeshTest::configurationPrimitive() {
    Corrade::Utility::Configuration c;

    c.setValue("primitive", Mesh::Primitive::LineStrip);
    CORRADE_COMPARE(c.value<std::string>("primitive"), "LineStrip");
    CORRADE_COMPARE(c.value<Mesh::Primitive>("primitive"), Mesh::Primitive::LineStrip);
}

void MeshTest::configurationIndexType() {
    Corrade::Utility::Configuration c;

    c.setValue("type", Mesh::IndexType::UnsignedByte);
    CORRADE_COMPARE(c.value<std::string>("type"), "UnsignedByte");
    CORRADE_COMPARE(c.value<Mesh::IndexType>("type"), Mesh::IndexType::UnsignedByte);
}

}}

CORRADE_TEST_MAIN(Magnum::Test::MeshTest)
