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

#ifndef DCDECOMODEL_TYPE_HXX
#define DCDECOMODEL_TYPE_HXX

#include "dcdecomodelType-fwd.hxx"

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

#include "applicationdataType-fwd.hxx"

namespace streit
{
  class dcdecomodelType: public ::streit::simpleNamedType
  {
    public:
    // applicationdata
    //
    typedef ::streit::applicationdataType applicationdata_type;
    typedef ::xsd::cxx::tree::optional< applicationdata_type > applicationdata_optional;
    typedef ::xsd::cxx::tree::traits< applicationdata_type, char > applicationdata_traits;

    const applicationdata_optional&
    applicationdata () const;

    applicationdata_optional&
    applicationdata ();

    void
    applicationdata (const applicationdata_type& x);

    void
    applicationdata (const applicationdata_optional& x);

    void
    applicationdata (::std::unique_ptr< applicationdata_type > p);

    // Constructors.
    //
    dcdecomodelType (const name_type&);

    dcdecomodelType (const ::xercesc::DOMElement& e,
                     ::xml_schema::flags f = 0,
                     ::xml_schema::container* c = 0);

    dcdecomodelType (const dcdecomodelType& x,
                     ::xml_schema::flags f = 0,
                     ::xml_schema::container* c = 0);

    virtual dcdecomodelType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    dcdecomodelType&
    operator= (const dcdecomodelType& x);

    virtual 
    ~dcdecomodelType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    applicationdata_optional applicationdata_;
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, const dcdecomodelType&);
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

#endif // DCDECOMODEL_TYPE_HXX
