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

#include "linkType.hxx"

#include "IDREF.hxx"

namespace streit
{
  // linkType
  //

  const linkType::ref_type& linkType::
  ref () const
  {
    return this->ref_.get ();
  }

  linkType::ref_type& linkType::
  ref ()
  {
    return this->ref_.get ();
  }

  void linkType::
  ref (const ref_type& x)
  {
    this->ref_.set (x);
  }

  void linkType::
  ref (::std::unique_ptr< ref_type > x)
  {
    this->ref_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // linkType
  //

  linkType::
  linkType (const ref_type& ref)
  : ::xml_schema::type (),
    ref_ (ref, this)
  {
  }

  linkType::
  linkType (const linkType& x,
            ::xml_schema::flags f,
            ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    ref_ (x.ref_, f, this)
  {
  }

  linkType::
  linkType (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f,
            ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    ref_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void linkType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "ref" && n.namespace_ ().empty ())
      {
        this->ref_.set (ref_traits::create (i, f, this));
        continue;
      }
    }

    if (!ref_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< char > (
        "ref",
        "");
    }
  }

  linkType* linkType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class linkType (*this, f, c);
  }

  linkType& linkType::
  operator= (const linkType& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->ref_ = x.ref_;
    }

    return *this;
  }

  linkType::
  ~linkType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const linkType& i)
  {
    o << ::std::endl << "ref: " << i.ref ();
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

