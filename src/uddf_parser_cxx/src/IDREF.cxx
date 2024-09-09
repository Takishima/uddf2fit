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

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "IDREF.hxx"

namespace streit
{
  // IDREF
  //
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // IDREF
  //

  IDREF::
  IDREF ()
  : ::xml_schema::token ()
  {
  }

  IDREF::
  IDREF (const char* _xsd_token_base)
  : ::xml_schema::token (_xsd_token_base)
  {
  }

  IDREF::
  IDREF (const ::std::string& _xsd_token_base)
  : ::xml_schema::token (_xsd_token_base)
  {
  }

  IDREF::
  IDREF (const ::xml_schema::token& _xsd_token_base)
  : ::xml_schema::token (_xsd_token_base)
  {
  }

  IDREF::
  IDREF (const IDREF& x,
         ::xml_schema::flags f,
         ::xml_schema::container* c)
  : ::xml_schema::token (x, f, c)
  {
  }

  IDREF::
  IDREF (const ::xercesc::DOMElement& e,
         ::xml_schema::flags f,
         ::xml_schema::container* c)
  : ::xml_schema::token (e, f, c)
  {
  }

  IDREF::
  IDREF (const ::xercesc::DOMAttr& a,
         ::xml_schema::flags f,
         ::xml_schema::container* c)
  : ::xml_schema::token (a, f, c)
  {
  }

  IDREF::
  IDREF (const ::std::string& s,
         const ::xercesc::DOMElement* e,
         ::xml_schema::flags f,
         ::xml_schema::container* c)
  : ::xml_schema::token (s, e, f, c)
  {
  }

  IDREF* IDREF::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class IDREF (*this, f, c);
  }

  IDREF::
  ~IDREF ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const IDREF& i)
  {
    o << static_cast< const ::xml_schema::token& > (i);

    return o;
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

