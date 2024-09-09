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

#ifndef TISSUE_TYPE_HXX
#define TISSUE_TYPE_HXX

#include "tissueType-fwd.hxx"

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

#include "gas-fwd.hxx"

namespace streit
{
  class tissueType: public ::xml_schema::type
  {
    public:
    // gas
    //
    typedef ::streit::gas gas_type;
    typedef ::xsd::cxx::tree::traits< gas_type, char > gas_traits;

    const gas_type&
    gas () const;

    gas_type&
    gas ();

    void
    gas (const gas_type& x);

    void
    gas (::std::unique_ptr< gas_type > p);

    // number
    //
    typedef ::xml_schema::int_ number_type;
    typedef ::xsd::cxx::tree::traits< number_type, char > number_traits;

    const number_type&
    number () const;

    number_type&
    number ();

    void
    number (const number_type& x);

    // halflife
    //
    typedef ::xml_schema::float_ halflife_type;
    typedef ::xsd::cxx::tree::traits< halflife_type, char > halflife_traits;

    const halflife_type&
    halflife () const;

    halflife_type&
    halflife ();

    void
    halflife (const halflife_type& x);

    // a
    //
    typedef ::xml_schema::float_ a_type;
    typedef ::xsd::cxx::tree::traits< a_type, char > a_traits;

    const a_type&
    a () const;

    a_type&
    a ();

    void
    a (const a_type& x);

    // b
    //
    typedef ::xml_schema::float_ b_type;
    typedef ::xsd::cxx::tree::traits< b_type, char > b_traits;

    const b_type&
    b () const;

    b_type&
    b ();

    void
    b (const b_type& x);

    // Constructors.
    //
    tissueType (const gas_type&,
                const number_type&,
                const halflife_type&,
                const a_type&,
                const b_type&);

    tissueType (const ::xercesc::DOMElement& e,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

    tissueType (const tissueType& x,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

    virtual tissueType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    tissueType&
    operator= (const tissueType& x);

    virtual 
    ~tissueType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< gas_type > gas_;
    ::xsd::cxx::tree::one< number_type > number_;
    ::xsd::cxx::tree::one< halflife_type > halflife_;
    ::xsd::cxx::tree::one< a_type > a_;
    ::xsd::cxx::tree::one< b_type > b_;
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, const tissueType&);
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

#endif // TISSUE_TYPE_HXX
