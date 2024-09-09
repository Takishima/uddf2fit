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

#ifndef PLATFORM_HXX
#define PLATFORM_HXX

#include "platform-fwd.hxx"

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
  class platform: public ::xml_schema::string
  {
    public:
    enum value
    {
      beach_shore,
      pier,
      small_boat,
      charter_boat,
      live_aboard,
      barge,
      landside,
      hyperbaric_facility,
      other
    };

    platform (value v);

    platform (const char* v);

    platform (const ::std::string& v);

    platform (const ::xml_schema::string& v);

    platform (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    platform (const ::xercesc::DOMAttr& a,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    platform (const ::std::string& s,
              const ::xercesc::DOMElement* e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    platform (const platform& x,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

#ifdef XSD_CXX11
    platform&
    operator= (const platform&) = default;
#endif

    virtual platform*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    platform&
    operator= (value v);

    virtual
    operator value () const
    {
      return _xsd_platform_convert ();
    }

    protected:
    value
    _xsd_platform_convert () const;

    public:
    static const char* const _xsd_platform_literals_[9];
    static const value _xsd_platform_indexes_[9];
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, platform::value);

  ::std::ostream&
  operator<< (::std::ostream&, const platform&);
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

#endif // PLATFORM_HXX
