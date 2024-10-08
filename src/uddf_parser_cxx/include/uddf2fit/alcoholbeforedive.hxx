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

#ifndef ALCOHOLBEFOREDIVE_HXX
#define ALCOHOLBEFOREDIVE_HXX

#include "alcoholbeforedive-fwd.hxx"

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

#include "drugType-fwd.hxx"

namespace streit
{
  class alcoholbeforedive: public ::xml_schema::type
  {
    public:
    // drink
    //
    typedef ::streit::drugType drink_type;
    typedef ::xsd::cxx::tree::sequence< drink_type > drink_sequence;
    typedef drink_sequence::iterator drink_iterator;
    typedef drink_sequence::const_iterator drink_const_iterator;
    typedef ::xsd::cxx::tree::traits< drink_type, char > drink_traits;

    const drink_sequence&
    drink () const;

    drink_sequence&
    drink ();

    void
    drink (const drink_sequence& s);

    // Constructors.
    //
    alcoholbeforedive ();

    alcoholbeforedive (const ::xercesc::DOMElement& e,
                       ::xml_schema::flags f = 0,
                       ::xml_schema::container* c = 0);

    alcoholbeforedive (const alcoholbeforedive& x,
                       ::xml_schema::flags f = 0,
                       ::xml_schema::container* c = 0);

    virtual alcoholbeforedive*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    alcoholbeforedive&
    operator= (const alcoholbeforedive& x);

    virtual 
    ~alcoholbeforedive ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    drink_sequence drink_;
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, const alcoholbeforedive&);
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

#endif // ALCOHOLBEFOREDIVE_HXX
