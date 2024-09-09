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

#include "gas.hxx"

namespace streit
{
  // gas
  //

  gas::
  gas (value v)
  : ::xml_schema::string (_xsd_gas_literals_[v])
  {
  }

  gas::
  gas (const char* v)
  : ::xml_schema::string (v)
  {
  }

  gas::
  gas (const ::std::string& v)
  : ::xml_schema::string (v)
  {
  }

  gas::
  gas (const ::xml_schema::string& v)
  : ::xml_schema::string (v)
  {
  }

  gas::
  gas (const gas& v,
       ::xml_schema::flags f,
       ::xml_schema::container* c)
  : ::xml_schema::string (v, f, c)
  {
  }

  gas& gas::
  operator= (value v)
  {
    static_cast< ::xml_schema::string& > (*this) = 
    ::xml_schema::string (_xsd_gas_literals_[v]);

    return *this;
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // gas
  //

  gas::
  gas (const ::xercesc::DOMElement& e,
       ::xml_schema::flags f,
       ::xml_schema::container* c)
  : ::xml_schema::string (e, f, c)
  {
    _xsd_gas_convert ();
  }

  gas::
  gas (const ::xercesc::DOMAttr& a,
       ::xml_schema::flags f,
       ::xml_schema::container* c)
  : ::xml_schema::string (a, f, c)
  {
    _xsd_gas_convert ();
  }

  gas::
  gas (const ::std::string& s,
       const ::xercesc::DOMElement* e,
       ::xml_schema::flags f,
       ::xml_schema::container* c)
  : ::xml_schema::string (s, e, f, c)
  {
    _xsd_gas_convert ();
  }

  gas* gas::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class gas (*this, f, c);
  }

  gas::value gas::
  _xsd_gas_convert () const
  {
    ::xsd::cxx::tree::enum_comparator< char > c (_xsd_gas_literals_);
    const value* i (::std::lower_bound (
                      _xsd_gas_indexes_,
                      _xsd_gas_indexes_ + 3,
                      *this,
                      c));

    if (i == _xsd_gas_indexes_ + 3 || _xsd_gas_literals_[*i] != *this)
    {
      throw ::xsd::cxx::tree::unexpected_enumerator < char > (*this);
    }

    return *i;
  }

  const char* const gas::
  _xsd_gas_literals_[3] =
  {
    "h2",
    "he",
    "n2"
  };

  const gas::value gas::
  _xsd_gas_indexes_[3] =
  {
    ::streit::gas::h2,
    ::streit::gas::he,
    ::streit::gas::n2
  };
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, gas::value i)
  {
    return o << gas::_xsd_gas_literals_[i];
  }

  ::std::ostream&
  operator<< (::std::ostream& o, const gas& i)
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

