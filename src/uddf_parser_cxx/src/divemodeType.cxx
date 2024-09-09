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

#include "divemodeType.hxx"

namespace streit
{
  // divemodeType
  //

  divemodeType::
  divemodeType (value v)
  : ::xml_schema::string (_xsd_divemodeType_literals_[v])
  {
  }

  divemodeType::
  divemodeType (const char* v)
  : ::xml_schema::string (v)
  {
  }

  divemodeType::
  divemodeType (const ::std::string& v)
  : ::xml_schema::string (v)
  {
  }

  divemodeType::
  divemodeType (const ::xml_schema::string& v)
  : ::xml_schema::string (v)
  {
  }

  divemodeType::
  divemodeType (const divemodeType& v,
                ::xml_schema::flags f,
                ::xml_schema::container* c)
  : ::xml_schema::string (v, f, c)
  {
  }

  divemodeType& divemodeType::
  operator= (value v)
  {
    static_cast< ::xml_schema::string& > (*this) = 
    ::xml_schema::string (_xsd_divemodeType_literals_[v]);

    return *this;
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // divemodeType
  //

  divemodeType::
  divemodeType (const ::xercesc::DOMElement& e,
                ::xml_schema::flags f,
                ::xml_schema::container* c)
  : ::xml_schema::string (e, f, c)
  {
    _xsd_divemodeType_convert ();
  }

  divemodeType::
  divemodeType (const ::xercesc::DOMAttr& a,
                ::xml_schema::flags f,
                ::xml_schema::container* c)
  : ::xml_schema::string (a, f, c)
  {
    _xsd_divemodeType_convert ();
  }

  divemodeType::
  divemodeType (const ::std::string& s,
                const ::xercesc::DOMElement* e,
                ::xml_schema::flags f,
                ::xml_schema::container* c)
  : ::xml_schema::string (s, e, f, c)
  {
    _xsd_divemodeType_convert ();
  }

  divemodeType* divemodeType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class divemodeType (*this, f, c);
  }

  divemodeType::value divemodeType::
  _xsd_divemodeType_convert () const
  {
    ::xsd::cxx::tree::enum_comparator< char > c (_xsd_divemodeType_literals_);
    const value* i (::std::lower_bound (
                      _xsd_divemodeType_indexes_,
                      _xsd_divemodeType_indexes_ + 5,
                      *this,
                      c));

    if (i == _xsd_divemodeType_indexes_ + 5 || _xsd_divemodeType_literals_[*i] != *this)
    {
      throw ::xsd::cxx::tree::unexpected_enumerator < char > (*this);
    }

    return *i;
  }

  const char* const divemodeType::
  _xsd_divemodeType_literals_[5] =
  {
    "apnea",
    "apnoe",
    "closedcircuit",
    "opencircuit",
    "semiclosedcircuit"
  };

  const divemodeType::value divemodeType::
  _xsd_divemodeType_indexes_[5] =
  {
    ::streit::divemodeType::apnea,
    ::streit::divemodeType::apnoe,
    ::streit::divemodeType::closedcircuit,
    ::streit::divemodeType::opencircuit,
    ::streit::divemodeType::semiclosedcircuit
  };
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, divemodeType::value i)
  {
    return o << divemodeType::_xsd_divemodeType_literals_[i];
  }

  ::std::ostream&
  operator<< (::std::ostream& o, const divemodeType& i)
  {
    return o << static_cast< const ::xml_schema::string& > (i);
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

