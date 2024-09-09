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

#include "suittype1.hxx"

namespace streit
{
  // suittype
  //

  suittype::
  suittype (value v)
  : ::xml_schema::string (_xsd_suittype_literals_[v])
  {
  }

  suittype::
  suittype (const char* v)
  : ::xml_schema::string (v)
  {
  }

  suittype::
  suittype (const ::std::string& v)
  : ::xml_schema::string (v)
  {
  }

  suittype::
  suittype (const ::xml_schema::string& v)
  : ::xml_schema::string (v)
  {
  }

  suittype::
  suittype (const suittype& v,
            ::xml_schema::flags f,
            ::xml_schema::container* c)
  : ::xml_schema::string (v, f, c)
  {
  }

  suittype& suittype::
  operator= (value v)
  {
    static_cast< ::xml_schema::string& > (*this) = 
    ::xml_schema::string (_xsd_suittype_literals_[v]);

    return *this;
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // suittype
  //

  suittype::
  suittype (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f,
            ::xml_schema::container* c)
  : ::xml_schema::string (e, f, c)
  {
    _xsd_suittype_convert ();
  }

  suittype::
  suittype (const ::xercesc::DOMAttr& a,
            ::xml_schema::flags f,
            ::xml_schema::container* c)
  : ::xml_schema::string (a, f, c)
  {
    _xsd_suittype_convert ();
  }

  suittype::
  suittype (const ::std::string& s,
            const ::xercesc::DOMElement* e,
            ::xml_schema::flags f,
            ::xml_schema::container* c)
  : ::xml_schema::string (s, e, f, c)
  {
    _xsd_suittype_convert ();
  }

  suittype* suittype::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class suittype (*this, f, c);
  }

  suittype::value suittype::
  _xsd_suittype_convert () const
  {
    ::xsd::cxx::tree::enum_comparator< char > c (_xsd_suittype_literals_);
    const value* i (::std::lower_bound (
                      _xsd_suittype_indexes_,
                      _xsd_suittype_indexes_ + 5,
                      *this,
                      c));

    if (i == _xsd_suittype_indexes_ + 5 || _xsd_suittype_literals_[*i] != *this)
    {
      throw ::xsd::cxx::tree::unexpected_enumerator < char > (*this);
    }

    return *i;
  }

  const char* const suittype::
  _xsd_suittype_literals_[5] =
  {
    "dive-skin",
    "wet-suit",
    "dry-suit",
    "hot-water-suit",
    "other"
  };

  const suittype::value suittype::
  _xsd_suittype_indexes_[5] =
  {
    ::streit::suittype::dive_skin,
    ::streit::suittype::dry_suit,
    ::streit::suittype::hot_water_suit,
    ::streit::suittype::other,
    ::streit::suittype::wet_suit
  };
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, suittype::value i)
  {
    return o << suittype::_xsd_suittype_literals_[i];
  }

  ::std::ostream&
  operator<< (::std::ostream& o, const suittype& i)
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

