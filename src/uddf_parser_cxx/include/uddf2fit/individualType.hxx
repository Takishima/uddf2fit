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

#ifndef INDIVIDUAL_TYPE_HXX
#define INDIVIDUAL_TYPE_HXX

#include "individualType-fwd.hxx"

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

#include "ID_TYPE.hxx"

#include "personalType-fwd.hxx"

#include "addressType-fwd.hxx"

#include "contactType-fwd.hxx"

namespace streit
{
  class individualType: public ::streit::ID_TYPE
  {
    public:
    // personal
    //
    typedef ::streit::personalType personal_type;
    typedef ::xsd::cxx::tree::traits< personal_type, char > personal_traits;

    const personal_type&
    personal () const;

    personal_type&
    personal ();

    void
    personal (const personal_type& x);

    void
    personal (::std::unique_ptr< personal_type > p);

    // address
    //
    typedef ::streit::addressType address_type;
    typedef ::xsd::cxx::tree::optional< address_type > address_optional;
    typedef ::xsd::cxx::tree::traits< address_type, char > address_traits;

    const address_optional&
    address () const;

    address_optional&
    address ();

    void
    address (const address_type& x);

    void
    address (const address_optional& x);

    void
    address (::std::unique_ptr< address_type > p);

    // contact
    //
    typedef ::streit::contactType contact_type;
    typedef ::xsd::cxx::tree::optional< contact_type > contact_optional;
    typedef ::xsd::cxx::tree::traits< contact_type, char > contact_traits;

    const contact_optional&
    contact () const;

    contact_optional&
    contact ();

    void
    contact (const contact_type& x);

    void
    contact (const contact_optional& x);

    void
    contact (::std::unique_ptr< contact_type > p);

    // Constructors.
    //
    individualType (const id_type&,
                    const personal_type&);

    individualType (const id_type&,
                    ::std::unique_ptr< personal_type >);

    individualType (const ::xercesc::DOMElement& e,
                    ::xml_schema::flags f = 0,
                    ::xml_schema::container* c = 0);

    individualType (const individualType& x,
                    ::xml_schema::flags f = 0,
                    ::xml_schema::container* c = 0);

    virtual individualType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    individualType&
    operator= (const individualType& x);

    virtual 
    ~individualType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< personal_type > personal_;
    address_optional address_;
    contact_optional contact_;
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, const individualType&);
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

#endif // INDIVIDUAL_TYPE_HXX
