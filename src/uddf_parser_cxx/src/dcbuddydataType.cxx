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

#include "dcbuddydataType.hxx"

#include "IDREF.hxx"

namespace streit
{
  // dcbuddydataType
  //

  const dcbuddydataType::buddy_type& dcbuddydataType::
  buddy () const
  {
    return this->buddy_.get ();
  }

  dcbuddydataType::buddy_type& dcbuddydataType::
  buddy ()
  {
    return this->buddy_.get ();
  }

  void dcbuddydataType::
  buddy (const buddy_type& x)
  {
    this->buddy_.set (x);
  }

  void dcbuddydataType::
  buddy (::std::unique_ptr< buddy_type > x)
  {
    this->buddy_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // dcbuddydataType
  //

  dcbuddydataType::
  dcbuddydataType (const buddy_type& buddy)
  : ::xml_schema::type (),
    buddy_ (buddy, this)
  {
  }

  dcbuddydataType::
  dcbuddydataType (const dcbuddydataType& x,
                   ::xml_schema::flags f,
                   ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    buddy_ (x.buddy_, f, this)
  {
  }

  dcbuddydataType::
  dcbuddydataType (const ::xercesc::DOMElement& e,
                   ::xml_schema::flags f,
                   ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    buddy_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void dcbuddydataType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "buddy" && n.namespace_ ().empty ())
      {
        this->buddy_.set (buddy_traits::create (i, f, this));
        continue;
      }
    }

    if (!buddy_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< char > (
        "buddy",
        "");
    }
  }

  dcbuddydataType* dcbuddydataType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class dcbuddydataType (*this, f, c);
  }

  dcbuddydataType& dcbuddydataType::
  operator= (const dcbuddydataType& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->buddy_ = x.buddy_;
    }

    return *this;
  }

  dcbuddydataType::
  ~dcbuddydataType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const dcbuddydataType& i)
  {
    o << ::std::endl << "buddy: " << i.buddy ();
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

