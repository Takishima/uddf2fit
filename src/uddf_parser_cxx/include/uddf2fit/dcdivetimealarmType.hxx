// Copyright (c) 2005-2023 Code Synthesis.
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis gives permission
// to link this program with the Xerces-C++ library (or with modified
// versions of Xerces-C++ that use the same license as Xerces-C++), and
// distribute linked combinations including the two. You must obey the GNU
// General Public License version 2 in all respects for all of the code
// used other than Xerces-C++. If you modify this copy of the program, you
// may extend this exception to your version of the program, but you are
// not obligated to do so. If you do not wish to do so, delete this
// exception statement from your version.
//
// Furthermore, Code Synthesis makes a special exception for the Free/Libre
// and Open Source Software (FLOSS) which is described in the accompanying
// FLOSSE file.
//

#ifndef DCDIVETIMEALARM_TYPE_HXX
#define DCDIVETIMEALARM_TYPE_HXX

#include "dcdivetimealarmType-fwd.hxx"

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (LIBXSD_VERSION != 400002000000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include <memory>    // ::std::unique_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search
#include <utility>   // std::move

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#include "dcalarmType-fwd.hxx"

namespace streit
{
  class dcdivetimealarmType: public ::xml_schema::type
  {
    public:
    // timespan
    //
    typedef ::xml_schema::float_ timespan_type;
    typedef ::xsd::cxx::tree::traits< timespan_type, char > timespan_traits;

    const timespan_type&
    timespan () const;

    timespan_type&
    timespan ();

    void
    timespan (const timespan_type& x);

    // dcalarm
    //
    typedef ::streit::dcalarmType dcalarm_type;
    typedef ::xsd::cxx::tree::traits< dcalarm_type, char > dcalarm_traits;

    const dcalarm_type&
    dcalarm () const;

    dcalarm_type&
    dcalarm ();

    void
    dcalarm (const dcalarm_type& x);

    void
    dcalarm (::std::unique_ptr< dcalarm_type > p);

    // Constructors.
    //
    dcdivetimealarmType (const timespan_type&,
                         const dcalarm_type&);

    dcdivetimealarmType (const timespan_type&,
                         ::std::unique_ptr< dcalarm_type >);

    dcdivetimealarmType (const ::xercesc::DOMElement& e,
                         ::xml_schema::flags f = 0,
                         ::xml_schema::container* c = 0);

    dcdivetimealarmType (const dcdivetimealarmType& x,
                         ::xml_schema::flags f = 0,
                         ::xml_schema::container* c = 0);

    virtual dcdivetimealarmType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    dcdivetimealarmType&
    operator= (const dcdivetimealarmType& x);

    virtual 
    ~dcdivetimealarmType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< timespan_type > timespan_;
    ::xsd::cxx::tree::one< dcalarm_type > dcalarm_;
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, const dcdivetimealarmType&);
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // DCDIVETIMEALARM_TYPE_HXX
