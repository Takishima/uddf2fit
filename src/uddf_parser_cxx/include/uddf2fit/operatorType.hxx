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

#ifndef OPERATOR_TYPE_HXX
#define OPERATOR_TYPE_HXX

#include "operatorType-fwd.hxx"

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

#include "simpleNamedType.hxx"

#include "addressType-fwd.hxx"

#include "contactType-fwd.hxx"

#include "ratingType-fwd.hxx"

#include "notesType-fwd.hxx"

namespace streit
{
  class operatorType: public ::streit::simpleNamedType
  {
    public:
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

    // rating
    //
    typedef ::streit::ratingType rating_type;
    typedef ::xsd::cxx::tree::sequence< rating_type > rating_sequence;
    typedef rating_sequence::iterator rating_iterator;
    typedef rating_sequence::const_iterator rating_const_iterator;
    typedef ::xsd::cxx::tree::traits< rating_type, char > rating_traits;

    const rating_sequence&
    rating () const;

    rating_sequence&
    rating ();

    void
    rating (const rating_sequence& s);

    // notes
    //
    typedef ::streit::notesType notes_type;
    typedef ::xsd::cxx::tree::optional< notes_type > notes_optional;
    typedef ::xsd::cxx::tree::traits< notes_type, char > notes_traits;

    const notes_optional&
    notes () const;

    notes_optional&
    notes ();

    void
    notes (const notes_type& x);

    void
    notes (const notes_optional& x);

    void
    notes (::std::unique_ptr< notes_type > p);

    // Constructors.
    //
    operatorType (const name_type&);

    operatorType (const ::xercesc::DOMElement& e,
                  ::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0);

    operatorType (const operatorType& x,
                  ::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0);

    virtual operatorType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    operatorType&
    operator= (const operatorType& x);

    virtual 
    ~operatorType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    address_optional address_;
    contact_optional contact_;
    rating_sequence rating_;
    notes_optional notes_;
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, const operatorType&);
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

#endif // OPERATOR_TYPE_HXX
