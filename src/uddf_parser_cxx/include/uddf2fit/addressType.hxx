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

#ifndef ADDRESS_TYPE_HXX
#define ADDRESS_TYPE_HXX

#include "addressType-fwd.hxx"

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

namespace streit
{
  class addressType: public ::xml_schema::type
  {
    public:
    // street
    //
    typedef ::xml_schema::string street_type;
    typedef ::xsd::cxx::tree::optional< street_type > street_optional;
    typedef ::xsd::cxx::tree::traits< street_type, char > street_traits;

    const street_optional&
    street () const;

    street_optional&
    street ();

    void
    street (const street_type& x);

    void
    street (const street_optional& x);

    void
    street (::std::unique_ptr< street_type > p);

    // city
    //
    typedef ::xml_schema::string city_type;
    typedef ::xsd::cxx::tree::optional< city_type > city_optional;
    typedef ::xsd::cxx::tree::traits< city_type, char > city_traits;

    const city_optional&
    city () const;

    city_optional&
    city ();

    void
    city (const city_type& x);

    void
    city (const city_optional& x);

    void
    city (::std::unique_ptr< city_type > p);

    // postcode
    //
    typedef ::xml_schema::string postcode_type;
    typedef ::xsd::cxx::tree::optional< postcode_type > postcode_optional;
    typedef ::xsd::cxx::tree::traits< postcode_type, char > postcode_traits;

    const postcode_optional&
    postcode () const;

    postcode_optional&
    postcode ();

    void
    postcode (const postcode_type& x);

    void
    postcode (const postcode_optional& x);

    void
    postcode (::std::unique_ptr< postcode_type > p);

    // country
    //
    typedef ::xml_schema::string country_type;
    typedef ::xsd::cxx::tree::traits< country_type, char > country_traits;

    const country_type&
    country () const;

    country_type&
    country ();

    void
    country (const country_type& x);

    void
    country (::std::unique_ptr< country_type > p);

    // province
    //
    typedef ::xml_schema::string province_type;
    typedef ::xsd::cxx::tree::optional< province_type > province_optional;
    typedef ::xsd::cxx::tree::traits< province_type, char > province_traits;

    const province_optional&
    province () const;

    province_optional&
    province ();

    void
    province (const province_type& x);

    void
    province (const province_optional& x);

    void
    province (::std::unique_ptr< province_type > p);

    // Constructors.
    //
    addressType (const country_type&);

    addressType (const ::xercesc::DOMElement& e,
                 ::xml_schema::flags f = 0,
                 ::xml_schema::container* c = 0);

    addressType (const addressType& x,
                 ::xml_schema::flags f = 0,
                 ::xml_schema::container* c = 0);

    virtual addressType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    addressType&
    operator= (const addressType& x);

    virtual 
    ~addressType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    street_optional street_;
    city_optional city_;
    postcode_optional postcode_;
    ::xsd::cxx::tree::one< country_type > country_;
    province_optional province_;
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, const addressType&);
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

#endif // ADDRESS_TYPE_HXX
